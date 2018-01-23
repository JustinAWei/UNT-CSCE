/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to implement the patrons class.
*/
#include <fstream>
#include <iostream>
#include <algorithm>
#include "patrons.h"
#include "patron.h"
using namespace std;

patrons::patrons() {
  id_count = 1;
  cout << "Constructing patrons!\n";
}

patrons::~patrons() {
  cout << "Destroying patrons!\n";
  //switches current roster with empty one, deallocating all memory.
  vector < patron > ().swap(roster);
}

int patrons::get_count() {
  return roster.size();
}

int patrons::get_id_count() {
  return id_count;
}

bool patrons::in (int id) {

  //return true if item exists
  for (int i = 0; i < roster.size(); i++) {
    if (roster[i].get_id() == id) {
      return true;
    }
  }
  return false;
}

patron & patrons::find(int id) {

  //finds the item and returns it
  for (int i = 0; i < roster.size(); i++) {
    if (roster[i].get_id() == id) {
      return roster[i];
    }
  }
}

void patrons::pay_fine() {
  //prompt for id
  int id;
  cout << "What is the id number of the patron? ";
  cin >> id;

  //check if found
  if ( in (id)) {
    //prompt for amount to pay
    float fine;
    cout << "Amount Paid?";
    cin >> fine;

    //pay
    find(id).pay_fine(fine);
  } else {
    cout << "Patron does not exist.\n";
  }
}

void patrons::print_mailing() {
  cout << "Printing all mailing labels.\n";
  for (int i = 0; i < roster.size(); i++) {
    cout << roster[i].get_name() << endl;
    cout << roster[i].get_address() << endl << endl;
  }
}

void patrons::print() {
  cout << "Printing all patrons.\n";
  for (int i = 0; i < roster.size(); i++) {
    cout << roster[i];
  }
}

void patrons::print_fines() {
  cout << "Printing all patrons with fines.\n";
  for (int i = 0; i < roster.size(); i++) {
    //if patron has fines
    if (roster[i].get_fine() > 0) {
      cout << roster[i];
    }
  }
}

void patrons::add() {

  //creates new patron
  patron p(id_count++);

  //inputs values into patron
  cin >> p;

  //adds to vector
  roster.push_back(p);

  //print details
  cout << p;
}

void patrons::add(patron p) {
  //add to vector
  roster.push_back(p);

  id_count++;

  //print details
  cout << p;
}

void patrons::remove() {

  //prompt for id
  int id;
  cout << "What is the id of the patron you wish to remove?\n";
  cin >> id;

  if ( in (id)) {
    patron & p = find(id);

    //don't erase if borrowing books or has fines
    if (p.get_num_books() > 0) {
      cout << p.get_name() << " currently has " << p.get_num_books() << " books checked out.\n";
      return;
    } else if (p.get_num_avs() > 0) {
      cout << p.get_name() << " currently has " << p.get_num_avs() << " AVs checked out.\n";
    } else if (p.get_fine() > 0) {
      cout << p.get_name() << " currently owes $" << p.get_fine() << " in fines.\n";
      return;
    }

    //else, erase
    for (vector < patron > ::iterator it = roster.begin(); it != roster.end(); it++) {
      if (it->get_id() == id) {
        roster.erase(it);
        return;
      }
    }

    //if failed to erase
    cout << "Could not erase for some reason.\n";
  } else {
    cout << "Patron does not exist.\n";
  }
}

void patrons::edit() {
  //prompt for id
  int id;
  cout << "What is the id of the patron you wish to edit?\n";
  cin >> id;

  //found
  if ( in (id)) {
    patron & p = find(id);

    string s;
    cout << "\nEditing Patron " << id << endl;

    //prompt for new attributes
    cout << "New name?\n";
    getline(cin, s);
    getline(cin, s);
    p.set_name(s);

    cout << "New address?\n";
    getline(cin, s);
    p.set_address(s);

    cout << "New phone?\n";
    getline(cin, s);
    p.set_phone(s);

    cout << "Sucessfully edited patron with id:" << p.get_id() << " | " << p.get_name() << endl;

  } else {
    cout << "Patron does not exist.\n";
  }
}

void patrons::save_patrons(FILE * fout) {
  int N = get_count();

  //write number of objects
  fprintf(fout, "%d\n", N);

  //write column headers
  fprintf(fout, "Patron ID | Name | Address | Phone | Status | Fine Balance | Num Books | Num AVs |\n");

  //for each obj print info
  for (int i = 0; i < N; i++) {
    int patron_id, num_books, num_avs;
    string name, status, address, phone;
    float fine;

    patron & p = roster[i];

    patron_id = p.get_id();
    name = p.get_name();
    address = p.get_address();
    phone = p.get_phone();
    status = p.get_status();
    fine = p.get_fine();
    num_books = p.get_num_books();
    num_avs = p.get_num_avs();

    fprintf(fout, "%d | %s | %s | %s | %s | %f | %d | %d |\n", patron_id, name.c_str(), address.c_str(), phone.c_str(), status.c_str(), fine, num_books, num_avs);
  }
  fprintf(fout, "\n");
}

void patrons::load_patrons(ifstream & fin) {
  string s;
  //get the number of rows
  int N;
  fin >> N;

  //skip headers
  getline(fin, s, '\n');
  getline(fin, s, '\n');
  //cout << s;

  //cout << N << endl;

  //loop through each row
  for (int n = 0; n < N; n++) {
    //cout << "COUNT " << n << endl;

    //patron attributes
    int patron_id, num_books, num_avs;
    string name, status, address, phone;
    float fine;

    fin >> patron_id >> s;
    getline(fin, name, '|');
    getline(fin, address, '|');
    getline(fin, phone, '|');
    getline(fin, status, '|');
    fin >> fine >> s;
    fin >> num_books >> s;
    fin >> num_avs >> s;

    getline(fin, s);
    //printf("%d %s %s %s %s %f %d %d", id, name.c_str(), address.c_str(), phone.c_str(), status.c_str(), fine, num_books, num_avs);

    //remove padding
    name = name.substr(1, name.length() - 2);
    address = address.substr(1, address.length() - 2);
    phone = phone.substr(1, phone.length() - 2);
    status = status.substr(1, status.length() - 2);

    //create a patron object with attributes
    patron p;
    p.set_id(patron_id);
    p.set_name(name);
    p.set_address(address);
    p.set_phone(phone);
    p.set_status(status);
    p.set_fine(fine);
    p.set_num_books(num_books);
    p.set_num_avs(num_avs);

    //add to list
    add(p);

    //printf("%d %s %s %s %s %f %d %d\n", patron_id, name.c_str(), address.c_str(), phone.c_str(), status.c_str(), fine, num_books, num_avs);
  }
}

ostream & operator << (ostream & output, patrons * ps) {
  ps->print();
  return output;
}

istream & operator >> (istream & input, patrons * ps) {
  ps->add();
  return input;
}
