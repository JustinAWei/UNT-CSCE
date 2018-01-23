/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 1040
Instructor: Keathly
Description: A class that controls many borrow structures.
*/

#include <string>
#include <iostream>
#include "borrow.h"
#include "borrows.h"
#include "books.h"
#include "patrons.h"

using namespace std;

borrows::borrows() {
  cout << "Contructing Borrows\n";
  head = tail = NULL;
  count = 0;
  id = 1;
}

borrows::~borrows() {
  cout << "Destroying Borrows\n";
  borrow* walk = head;
  for (int i = 0; i < count; i++) {
    borrow* temp = walk;
    walk = walk->get_next();
    delete temp;
  }
}

void borrows::calculate_fines(patrons* ps) {
  cout << "Calculating Fines...\n";
  borrow* walk = head;
  for (int i = 0; i < count; i++) {
    if (walk->get_due() < time(0) && ps->find_patron(walk->get_patron_id()) != NULL) {
      ps->find_patron(walk->get_patron_id())->add_fine(FINE_RATE);
    }
    walk = walk->get_next();
  }
  return;
}

borrow* borrows::get_head(){
  return head;
}

void borrows::print_overdue_patrons(patrons* ps, books* bs) {
  cout << "Printing all patrons with overdue books.\n";
  borrow* walk = head;
  for (int i = 0; i < count; i++) {
    if (walk->get_due() < time(0) && ps->find_patron(walk->get_patron_id()) != NULL) {
      ps->find_patron(walk->get_patron_id())->print();
    }
    walk = walk->get_next();
  }
  return;
}

void borrows::print_patron_books(patrons* ps, books* bs) {
  int p;
  cout << "What is the id number of the patron? ";
  cin >> p;
  if (ps->find_patron(p) == NULL) {
    cout << "Patron does not exist.\n";
    return;
  }
  if (ps->find_patron(p)->get_num_borrowed() <= 0) {
    cout << "Patron does not have any books.\n";
    return;
  }

  cout << "Printing all books borrowed by " << ps->find_patron(p)->get_name() << ".\n";

  borrow* walk = head;
  for (int i = 0; i < count; i++) {
    if (walk->get_patron_id() == p && bs->find_book(walk->get_book_id()) != NULL) {
      bs->find_book(walk->get_book_id())->print();
    }
    walk = walk->get_next();
  }
  return;
}

int borrows::get_count() {
  return count;
}

int borrows::get_id() {
  return id;
}

void borrows::print() {
  borrow* walk = head;
  for (int i = 0; i < count; i++) {
    walk->print();
    walk = walk->get_next();
  }
}

void borrows::check_out(patrons* ps, books* bs) {
  patron* p;
  borrow* b = new borrow;
  int i, pi, bi;
  string s;
  float f;

  b->set_trans_id(id);

  cout << "Checking out or renewing a book.\n";

  cout << "What is the id number of the patron? ";
  cin >> pi;
  b->set_patron_id(pi);

  cout << "What is the id number of the book? ";
  cin >> bi;
  b->set_book_id(bi);

  //if transaction already exists
  if (find(pi, bi) != NULL) {
    borrow* temp = find(pi, bi);

    //if renewal is available
    if (temp->get_recheck()) {
      cout << "Our records show this patron already has this book. We will renew it for you.\n";

      //update due date with two weeks of seconds
      temp->set_due(temp->get_due() + CHECK_OUT_PERIOD);

      //mark as renewed
      temp->set_recheck(false);
      time_t t = temp->get_due();
      cout << "It is now due on: " << ctime( & t) << endl;
    } else {
      cout << "Our records show this patron has already renewed this book.\n";
    }
  } else {
    cout << "Creating new transaction.\n";
    //set due date 2 weeks from now
    b->set_due(time(0) + CHECK_OUT_PERIOD);

    b->set_recheck(true);

    //if patron is able to check out
    if (ps->find_patron(b->get_patron_id()) != NULL && ps->find_patron(b->get_patron_id())->get_num_borrowed() < 5) {
      p = ps->find_patron(b->get_patron_id());

      //add one to num borrowed
      p->set_num_borrowed(p->get_num_borrowed() + 1);
      id++;
    } else {
      cout << "This patron either does not exist or has already checked out the maximum of five books." << endl;
      return;
    }

    //if book is able to be checked out
    if (bs->find_book(b->get_book_id()) != NULL && bs->find_book(b->get_book_id())->get_status() == "IN") {
      //set book status to out
      bs->find_book(b->get_book_id())->set_status("OUT");
      //add the borrow object to the list
      if (head == NULL) {
        head = tail = b;
      } else {
        tail->set_next(b);
        tail->get_next()->set_prev(tail);
        tail = b;
      }
      cout << "Sucessfully checked out.\n";
      count++;

    } else {
      //revert the addition to num borrowed
      p->set_num_borrowed(p->get_num_borrowed() - 1);
      cout << "This book either does not exist, is lost, or is already checked out\n";
      return;
    }
  }

  bs->find_book(b->get_book_id())->print();
  ps->find_patron(b->get_patron_id())->print();

}

void borrows::add_borrow(borrow* b, books* bs, patrons* ps) {
  //add the borrow object to the list
  if (head == NULL) {
    head = tail = b;
  } else {
    tail->set_next(b);
    tail->get_next()->set_prev(tail);
    tail = b;
  }
  cout << "Sucessfully Added Borrows.\n";
  count++;
  id++;
  b->print();
  book* bk = bs->find_book(b->get_book_id());
  patron* p = ps->find_patron(b->get_patron_id());
  p->print();
  bk->print();
}

void borrows::check_in(int p, int b, patrons* ps, books* bs) {
  borrow* walk = find(p, b);
  patron* pa;

  if (walk != NULL) {

    //if patron is able to check in
    if (ps->find_patron(p) != NULL && ps->find_patron(p)->get_num_borrowed() > 0) {
      pa = ps->find_patron(p);
      //subtract one from numborrowed
      pa->set_num_borrowed(pa->get_num_borrowed() - 1);
    } else {
      cout << "This patron either does not exist or has no books checked out." << endl;
      return;
    }

    //if book is able to be checked in
    if (bs->find_book(b) != NULL && bs->find_book(b)->get_status() == "OUT") {
      // set status to in
      bs->find_book(b)->set_status("IN");
    } else {
      //rever the subtraction from numborrowed
      pa->set_num_borrowed(pa->get_num_borrowed() + 1);
      cout << "This book either does not exist, is lost, or is already checked in\n";
      return;
    }

    if (walk == head && walk == tail) {
      //cout << "BOTH" << endl;
      head = tail = NULL;
    } else if (walk == head) {
      head = walk->get_next();
    } else if (walk == tail) {
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
    count--;
  }
}

borrow* borrows::find(int p, int b) {
  borrow* walk = head;
  for (int j = 0; j < count; j++) {
    if (walk->get_patron_id() == p && walk->get_book_id() == b) {
      return walk;
    }
    walk = walk->get_next();
  }
  return NULL;
}

void borrows::print_overdue(patrons* ps, books* bs) {
  borrow* walk = head;
  for (int i = 0; i < count; i++) {
    //if both the book and patron exists,
    if (ps->find_patron(walk->get_patron_id()) != NULL && bs->find_book(walk->get_book_id()) != NULL) {
      //if its the book is checked out and is overdue, print it
      if (bs->find_book(walk->get_book_id())->get_status() == "OUT" && walk->get_due() < time(0)) {
        walk->print();
      }
    }
    walk = walk->get_next();
  }
}
