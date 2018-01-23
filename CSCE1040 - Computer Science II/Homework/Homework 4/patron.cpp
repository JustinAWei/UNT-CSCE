/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 1040
Instructor: Keathly
Description: A class that handles set/get of the patron structure
*/
#include "patron.h"

using namespace std;

patron::patron() {
  next = prev = NULL;
}

void patron::print() {
  cout << endl;
  cout << "Patron ID: " << patron_id << endl;
  cout << "Num Borrowed: " << num_borrowed << endl;
  cout << "Name: " << name << endl;
  cout << "Status: " << status << endl;
  cout << "Address: " << address << endl;
  cout << "Phone: " << phone << endl;
  cout << "Fine Balance: $" << fine << endl;
  cout << endl;
}

void patron::set_id(int i) {
  patron_id = i;
}

void patron::set_next(patron * p) {
  next = p;
}

void patron::set_prev(patron * p) {
  prev = p;
}

void patron::set_num_borrowed(int i) {
  num_borrowed = i;

  //patron is blocked from checking out more books if he has checked out 5 books
  if (num_borrowed >= 5) {
    status = "BAD";
  } else if (fine <= 0) {
    status = "GOOD";
  }
}

void patron::set_name(string s) {
  name = s;
}
void patron::set_status(string s) {
  status = s;
}

void patron::set_address(string s) {
  address = s;
}

void patron::set_phone(string s) {
  phone = s;
}

void patron::set_fine(float f) {
  fine = f;
}

int patron::get_id() {
  return patron_id;
}

int patron::get_num_borrowed() {
  return num_borrowed;
}

string patron::get_name() {
  return name;
}

string patron::get_status() {
  return status;
}

string patron::get_address() {
  return address;
}

string patron::get_phone() {
  return phone;
}

float patron::get_fine() {
  return fine;
}

void patron::add_fine(float i) {
  //if patron's fines are above 0, status is bad
  fine += i;
  status = "BAD";
}

void patron::add_book_cost(float i) {
  //if patron's fines are above 0, status is bad
  fine += i;
  status = "BAD";
}


void patron::pay_fine(float i) {
  fine -= i;
  //if patron's fines are not above 0, status is GOOD, but only if he has less than 5 books checked out
  if (fine <= 0) {
    fine = 0;
    if (num_borrowed < 5) {
      status = "GOOD";
    }
  }
}

patron * patron::get_next() {
  return next;
}

patron * patron::get_prev() {
  return prev;
}
