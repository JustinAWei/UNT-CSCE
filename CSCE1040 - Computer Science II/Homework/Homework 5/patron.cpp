/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to implement the patron class.
*/

#include "patron.h"

using namespace std;

patron::patron() {
  fine = 0;
  patron_id = 0;
  num_books = 0;
  num_avs = 0;
  status = "GOOD";
  name = address = phone = "";
}

patron::patron(int id) {
  fine = 0;
  patron_id = 0;
  num_books = 0;
  num_avs = 0;
  status = "GOOD";
  name = address = phone = "";

  patron_id = id;
}

void patron::print() {
  cout << endl;
  cout << "Patron ID: " << patron_id << endl;
  cout << "Num Books: " << num_books << endl;
  cout << "Num AVS: " << num_avs << endl;
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

void patron::set_num_books(int i) {
  num_books = i;

  //patron is blocked from checking out more books if he has checked out 5 books
  if (num_books >= 5 || num_avs >= 2) {
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

void patron::set_num_avs(int i) {
  num_avs = i;
  //patron is blocked from checking out more books if he has checked out 5 books
  if (num_books >= 5 || num_avs >= 2) {
    status = "BAD";
  } else if (fine <= 0) {
    status = "GOOD";
  }
}

int patron::get_id() {
  return patron_id;
}

int patron::get_num_books() {
  return num_books;
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

int patron::get_num_avs() {
  return num_avs;
}
void patron::add_fine(float i) {
  //if patron's fines are above 0, status is bad
  fine += i;
  status = "BAD";
}

void patron::pay_fine(float i) {
  //Error checking
  if (i > fine) {
    cout << name << " cannot overpay your fines. Please enter a value equal to or below $" << fine << endl;
    cout << "His/Her status is now: " << status << endl;
    return;
  }
  fine -= i;
  //if patron's fines are not above 0, status is GOOD, but only if he has less than 5 books checked out
  if (fine <= 0) {
    fine = 0;
    if (num_books < 5 && num_avs < 2) {
      status = "GOOD";
    }
  }

  //print
  cout << name << " has paid $" << i << " towards his/her fines.\n";
  cout << "His/Her status is now: " << status << endl;
}

bool patron::check_fine() {
  //true if patron has no fines
  if (fine > 0) {
    cout << "Patron currently has $" << get_fine() << " in fines.\n";
    return false;
  } else {
    return true;
  }
}

bool patron::check_limit(string type) {
  //true if patron can check out an item of the appropriate type
  if (type == "Book") {
    if (get_num_books() >= 5) {
      cout << "Patron currently has " << get_num_books() << " books checked out.\n";
      return false;
    }
  } else if (type == "CD" || type == "DVD") {
    if (get_num_avs() >= 2) {
      cout << "Patron currently has " << get_num_avs() << " AVs checked out.\n";
      return false;
    }
  } else {
    return false;
  }
  return true;
}

ostream & operator << (ostream & output, patron p) {
  p.print();
  return output;
}

istream & operator >> (istream & input, patron & p) {
  string name, address, phone;

  cout << "What is the name of the patron?\n";
  getline(cin, name);
  getline(cin, name);

  cout << "What is the address of the patron?\n";
  getline(cin, address);

  cout << "What is the phone of the patron?\n";
  getline(cin, phone);

  p.set_name(name);
  p.set_address(address);
  p.set_phone(phone);

  return input;
}
