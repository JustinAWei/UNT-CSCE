/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 1040
Instructor: Keathly
Description: A class that handles set/get of the borrow structure
*/
#include <string>
#include <iostream>
#include "borrow.h"
using namespace std;

borrow::borrow() {
  next = prev = NULL;
}

void borrow::print() {
  cout << endl;
  cout << "trans_id: " << trans_id << endl;
  cout << "book_id: " << book_id << endl;
  cout << "patron_id: " << patron_id << endl;
  cout << "Due: " << ctime(&due) << endl;
  cout << endl;
}

void borrow::set_recheck(bool i) {
  recheck = i;
}

void borrow::set_trans_id(int i) {
  trans_id = i;
}

void borrow::set_book_id(int i) {
  book_id = i;
}

void borrow::set_patron_id(int i) {
  patron_id = i;
}

void borrow::set_due(time_t i) {
  due = i;
}

int borrow::get_trans_id() {
  return trans_id;
}
int borrow::get_book_id() {
  return book_id;
}
int borrow::get_patron_id() {
  return patron_id;
}
time_t borrow::get_due() {
  return due;
}
bool borrow::get_recheck() {
  return recheck;
}

void borrow::set_next(borrow * p) {
  next = p;
}

void borrow::set_prev(borrow * p) {
  prev = p;
}

borrow * borrow::get_next() {
  return next;
}

borrow * borrow::get_prev() {
  return prev;
}
