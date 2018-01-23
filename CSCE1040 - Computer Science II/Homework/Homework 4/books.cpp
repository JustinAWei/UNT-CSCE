/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 1040
Instructor: Keathly
Description: A class that controls many book structures.
*/

#include <iostream>
#include <string>
#include "books.h"
#include "borrows.h"
#include "patrons.h"
using namespace std;

void books::print() {
  book* walk = head;
  for(int i =0; i < count; i++) {
    walk->print();
    walk = walk->get_next();
  }
}

books::books(){
  cout << "Constructing Books\n";
  count = 0;
  id = 1;
  head = tail = NULL;
}

books::~books(){
  cout << "Destroying books\n";
  book* walk = head;
  for(int j = 0; j < count; j++) {
    book* temp = walk;
    walk = walk->get_next();
    delete temp;
  }
}


book* books::get_head(){
  return head;
}

void books::add_book(){

  count++;
  cout << "Adding new book.\n";
  book *b = new book;
  int i;
  string s;
  float f;

  b->set_book_id(id++);

  cout << "Title?";
  getline(cin, s);
  getline(cin, s);
  b->set_title(s);

  cout << "Publisher?";
  getline(cin, s);
  b->set_publisher(s);

  cout << "Cost?";
  cin >> f;
  b->set_cost(f);

  //all new books will be 'IN'
  b->set_status("IN");

  if (head == NULL) {
  //  cout << "head is NULL" << endl;
    head = tail = b;
  } else {
    tail->set_next(b);
    tail->get_next()->set_prev(tail);
    tail = b;
  }
  cout << "Sucessfully added book\n";
  b->print();
}

void books::add_book(book* b){
  if (head == NULL) {
  //  cout << "head is NULL" << endl;
    head = tail = b;
  } else {
    tail->set_next(b);
    tail->get_next()->set_prev(tail);
    tail = b;
  }
  count++;
  id++;
  cout << "Sucessfully added book\n";
  b->print();
}

void books::edit_book() {

  cout << "Editing existing book." << endl;

  int i;
  string s;
  float f;

  cout << "What is the id number of the book? ";
  cin >> i;
  if (find_book(i) != NULL) {
    book *p = find_book(i);

    cout << "\nEditing book " << i << endl;

    cout << "Title?\n";
    getline(cin, s);
    getline(cin, s);
    p->set_title(s);

    cout << "Publisher?\n";
    getline(cin, s);
    p->set_publisher(s);

    cout << "Cost?";
    cin >> f;
    p->set_cost(f);

    cout << "Sucessfully edited book with id:" << p->get_book_id() << " | " << p->get_title() << endl;
    p->print();
  } else {
    cout << "Book does not exist.\n";
  }
}


void books::remove_book(){
  cout << "Removing existing book\n";

  int i;
  cout << "Book ID?";
  cin >> i;

  book* walk = head;

  while(walk != NULL) {
    if(walk->get_book_id() == i) {
      if (walk->get_status() == "OUT") {
        cout << walk->get_title() << " cannot be deleted because it is checked out.\n";
        return;
      }
      //book is not checked out
      if (walk == head && walk == tail) {
        //cout << "BOTH" << endl;
        head = tail = NULL;
      }
      else if (walk == head) {
        head = walk->get_next();
      }
      else if (walk == tail) {
        tail = walk->get_prev();
      }
      if (walk->get_prev() != NULL) {
        //cout << "PREVIOUS ISN'T NULL" << endl;
        walk->get_prev()->set_next(walk->get_next());
      }
      if (walk->get_next() != NULL) {
        //cout << "NEXT ISN'T NULL" << endl;
        walk->get_next()->set_prev(walk->get_prev());
      }
      delete walk;
      cout << "Successfully removed book " << i << "."<< endl;
      count--;
      return;
    }
    walk = walk->get_next();
  }
  cout << "Book " << i << " cannot be deleted because does not exist.\n";
}

void books::lose(patrons* ps, borrows* bw){

  int p,b;

  char lib;
  cout << "Is a patron reporting the book as lost? (y/n) ";
  cin >> lib;
  if(lib == 'y') {
    cout << "What is the id number of the patron? ";
    cin >> p;
  } else {
    p = -1;
  }

  cout << "What is the id number of the book? ";
  cin >> b;

  //if librarian reports missing
  if(p < 0) {
    book* bo = find_book(b);
    //if found
    if(bo != NULL) {
      //set status on lost
      bo->set_status("LOST");
      cout << "Successfully recorded book as LOST.\n";
    } else {
      cout << "Book does not exist.\n";
    }
    return;
  } else {

    //delete the transaction
    bw->check_in(p,b, ps, this);

    //record as lost
    book* walk = head;
    float cost;
    for(int j = 0; j < count; j++) {
      if(walk->get_book_id() == b) {
        walk->set_status("LOST");
        cost = walk->get_cost();
        cout << "COST " << cost << endl;
        break;
      }
      walk = walk->get_next();
    }

    //give fine to patron
    ps->find_patron(p)->add_fine(cost);
  }
  if (ps->find_patron(p) != NULL) {
    ps->find_patron(p)->print();
  }
  if (find_book(b) != NULL) {
    find_book(b)->print();
  }

}


book* books::find_book(int i) {
  book* walk = head;
  for(int j = 0; j < count; j++) {
    if(walk->get_book_id() == i) {
      return walk;
      break;
    }
    walk = walk->get_next();
  }
  return NULL;
}

int books::get_count(){
  return count;
}

int books::get_id(){
  return id;
}
