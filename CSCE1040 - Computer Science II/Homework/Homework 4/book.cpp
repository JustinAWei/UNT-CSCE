/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 1040
Instructor: Keathly
Description: A class that handles set/get of the book structure
*/

#include <string>
#include <iostream>
#include "borrow.h"
#include "borrows.h"
#include "books.h"
#include "patrons.h"

using namespace std;

void book::print() {
  cout << "Book ID: " << book_id << endl;
  cout << "Title: " << title << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Status: " << status << endl;
  cout << "Cost: " << cost << endl;
}

book::book(){
  next = prev = NULL;
}

void book::set_book_id(int i) {
  book_id = i;
}

void book::set_title(string s) {
  title = s;
}

void book::set_publisher(string s) {
  publisher = s;
}

void book::set_status(string s) {
  status = s;
}

void book::set_cost(float f) {
  cost = f;
}

int book::get_book_id() {
  return book_id;
}

string book::get_title() {
  return title;
}

string book::get_publisher() {
  return publisher;
}

string book::get_status() {
  return status;
}

float book::get_cost() {
  return cost;
}

void book::set_next(book *p) {
  next = p;
}

void book::set_prev(book *p) {
  prev = p;
}

book *book::get_next() {
  return next;
}

book *book::get_prev() {
  return prev;
}
