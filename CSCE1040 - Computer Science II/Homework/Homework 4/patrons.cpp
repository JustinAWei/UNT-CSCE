/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 1040
Instructor: Keathly
Description: A class that controls many patron structures.
*/

#include <string>
#include <iostream>
#include "patrons.h"

using namespace std;

patrons::patrons() {
  cout << "Constructing patrons\n";
  count = 0;
  id = 1;
  head = tail = NULL;
}

patrons::~patrons() {
  cout << "Destroying patrons\n";
  patron* walk = head;
  for (int j = 0; j < count; j++) {
    patron* temp = walk;
    walk = walk->get_next();
    delete temp;
  }
}

void patrons::pay_fine() {
  int i;
  float f;

  cout << "What is the id number of the patron? ";
  cin >> i;

  cout << "Amount Paid?";
  cin >> f;

  if (find_patron(i) != NULL) {

    find_patron(i)->pay_fine(f);
    cout << find_patron(i)->get_name() << " has paid $" << f << " towards his/her fines.\n";
    cout << "His/Her status is now: " << find_patron(i)->get_status() << endl;
  } else {
    cout << "Patron does not exist" << endl;
  }
}

patron* patrons::get_head(){
  return head;
}

int patrons::get_count() {
  return count;
}

int patrons::get_id() {
  return id;
}

void patrons::add_patron() {
  int i;
  string s;

  count++;

  cout << "Adding new patron.\n";
  patron* p = new patron;

  p->set_id(id++);

  cout << "Name?";
  getline(cin, s);
  getline(cin, s);
  p->set_name(s);

  cout << "Address?";
  getline(cin, s);
  p->set_address(s);

  cout << "Phone?";
  getline(cin, s);
  p->set_phone(s);

  //new patrons will have these standard parameters
  p->set_num_borrowed(0);
  p->set_status("GOOD");
  p->set_fine(0);

  if (head == NULL) {
    //cout << "head is NULL" << endl;
    head = tail = p;
  } else {
    tail->set_next(p);
    tail->get_next()->set_prev(tail);
    tail = p;
  }
  cout << "Sucessfully added patron.\n";

  //print patron details
  p->print();

}

void patrons::add_patron(patron* p){

  if (head == NULL) {
    //cout << "head is NULL" << endl;
    head = tail = p;
  } else {
    tail->set_next(p);
    tail->get_next()->set_prev(tail);
    tail = p;
  }
  count++;
  id++;
  cout << "Sucessfully added patron.\n";

  //print patron details
  p->print();

}


void patrons::edit_patron() {
  //Check if patron exists...

  int i;
  string s;
  float f;

  cout << "What is the id number of the patron? ";
  cin >> i;
  if (find_patron(i) != NULL) {
    cout << "Editing an existing patron.\n" << endl;
    patron* p = find_patron(i);

    cout << "\nEditing Patron " << i << endl;

    cout << "New name?\n";
    getline(cin, s);
    getline(cin, s);
    p->set_name(s);

    cout << "New address?\n";
    getline(cin, s);
    p->set_address(s);

    cout << "New phone?\n";
    getline(cin, s);
    p->set_phone(s);

    cout << "Sucessfully edited patron with id:" << p->get_id() << " | " << p->get_name() << endl;
    find_patron(p->get_id())->print();
  } else {
    cout << "Patron does not exist.\n";
  }
}

void patrons::remove_patron() {
  cout << "Removing an existing patron.\n";

  int i;
  cout << "Patron ID?";
  cin >> i;
  patron* walk = head;
  while (walk != NULL) {
    //if patron if found
    if (walk->get_id() == i) {
      //don't delete patron with books checked out or outstanding fines
      if (walk->get_fine() == 0 && walk->get_num_borrowed() == 0) {
        //delete
        if (walk == head && walk == tail) {
          head = tail = NULL;
        } else if (walk == head) {
          head = walk->get_next();
        } else if (walk == tail) {
          tail = walk->get_prev();
        }
        if (walk->get_prev() != NULL) {
          walk->get_prev()->set_next(walk->get_next());
        }
        if (walk->get_next() != NULL) {
          walk->get_next()->set_prev(walk->get_prev());
        }
        delete walk;
        cout << "Successfully removed patron " << i << "." << endl;
        count--;
        return;
      } else {
        cout << walk->get_name() << " cannot be deleted due to unpaid fines and/or borrowed books.\n";
        cout << "Fine Balance: " << walk->get_fine() << endl;
        cout << "Num of books borrowed: " << walk->get_num_borrowed() << endl;
        return;
      }
    }
    walk = walk->get_next();
  }
  cout << "Patron cannot be deleted because it does not exist.\n";
}

void patrons::print() {
  cout << "Printing all patrons:\n";
  patron* walk = head;
  while (walk != NULL) {
    walk->print();
    walk = walk->get_next();
  }
}

void patrons::print_fines() {
  cout << "Printing all patrons with fines:\n";
  patron* walk = head;
  for (int j = 0; j < count; j++) {
    if (walk->get_fine() > 0) {
      walk->print();
    }
    walk = walk->get_next();
  }
}

void patrons::print_mailing() {
  cout << "Printing all mailing labels" << endl;
  patron* walk = head;
  for (int j = 0; j < count; j++) {
    cout << walk->get_name() << "\n" << walk->get_address() << "\n\n";
    walk = walk->get_next();
  }
}

patron* patrons::find_patron(int i) {
  patron* walk = head;
  for (int j = 0; j < count; j++) {
    if (walk->get_id() == i) {
      return walk;
      break;
    }
    walk = walk->get_next();
  }
  return NULL;
}
