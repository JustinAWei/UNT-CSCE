/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to implement the transaction class.
*/

#include "transaction.h"

using namespace std;

//Constructors
transaction::transaction() {
  cout << "What is the ID number of the patron that is checking out the item? ";
  cin >> patron_id;

  cout << "What is the ID number of the item that being checked out? ";
  cin >> item_id;
}

transaction::transaction(int i) {
  id = i;
}

//Getters
int transaction::get_id() {
  return id;
}
int transaction::get_patron_id() {
  return patron_id;
}
string transaction::get_item_id() {
  return item_id;
}
time_t transaction::get_due() {
  return due;
}
bool transaction::is_renewable() {
  return renewable;
}

//Setters
void transaction::set_id(int i) {
  id = i;
}
void transaction::set_patron_id(int i) {
  patron_id = i;
}
void transaction::set_item_id(string s) {
  item_id = s;
}
void transaction::set_due(time_t t) {
  due = t;
}
void transaction::renew() {
  renewable = false;
}
void transaction::set_renewable(bool b) {
  renewable = b;
}
bool transaction::is_overdue() {
  return (time(0) - due > 0) ? true : false;
}

void transaction::print() {
  cout << "Transaction ID: " << id << endl;
  cout << "Patron ID: " << patron_id << endl;
  cout << "Item ID: " << item_id << endl;
  cout << "Due: " << ctime( & due);
  cout << "Renewable: " << renewable << endl << endl;
}
ostream & operator << (ostream & output, transaction t) {
  t.print();
  return output;
}

istream & operator >> (istream & input, transaction t) {
  //transaction cannot be modified
  return input;
}
