/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to implement the libitem class.
*/

#include "libitem.h"
#include <sstream>

using namespace std;

//Constructors
libitem::libitem() {
  renewable = true;
  borrowable = true;
  fine_rate = 0;
  replacement_cost = 0;
  loan_period = 0;
  id = "";
  status = "IN";
  type = "libitem";
}

//Getters
bool libitem::is_renewable() {
  return renewable;
}
bool libitem::is_borrowable() {
  return borrowable;
}
string libitem::get_id() {
  return id;
}
string libitem::get_status() {
  return status;
}
time_t libitem::get_loan_period() {
  return loan_period;
}
float libitem::get_fine_rate() {
  return fine_rate;
}
float libitem::get_replacement_cost() {
  return replacement_cost;
}

//Setters
void libitem::set_id(string s) {
  id = s;
}
void libitem::set_status(string s) {
  status = s;
}
void libitem::set_loan_period(time_t t) {
  loan_period = t;
}
void libitem::set_fine_rate(float f) {
  fine_rate = f;
}
void libitem::set_replacement_cost(float f) {
  replacement_cost = f;
}
void libitem::set_borrowable(bool b) {
  borrowable = b;
}
void libitem::set_renewable(bool b) {
  renewable = b;
}

void libitem::print() {
  cout << type << " ID: " << id << endl;
  cout << "Status: " << status << endl;
  cout << "Replacement Cost: $" << replacement_cost << endl;
  cout << "Fine Rate: $" << fine_rate << endl;
  cout << "Renewable: " << boolalpha << renewable << endl;
  cout << "Borrowable: " << boolalpha << borrowable << endl;
  cout << "Loan Period: " << loan_period / 86400 << " days." << endl;
}

string libitem::get_type() {
  return type;
}

string libitem::get_attributes() {
  string ret = "";

  //convert all numeric values to strings
  string sid, sloan_period, sfine_rate, sreplacement_cost, srenewable, sborrowable;
  stringstream ss;
  ss << id;
  ss >> sid;
  ss.clear();

  ss << loan_period;
  ss >> sloan_period;
  ss.clear();

  ss << fine_rate;
  ss >> sfine_rate;
  ss.clear();

  ss << replacement_cost;
  ss >> sreplacement_cost;
  ss.clear();

  ss << renewable;
  ss >> srenewable;
  ss.clear();

  ss << borrowable;
  ss >> sborrowable;
  ss.clear();

  /*  cout << id << endl;
    cout << sid << endl;

    cout << loan_period << endl;
    cout << sloan_period << endl;

    cout << fine_rate << endl;
    cout << sfine_rate << endl;

    cout << replacement_cost << endl;
    cout << sreplacement_cost << endl;

    cout << renewable << endl;
    cout << srenewable << endl;

    cout << borrowable << endl;
    cout << sborrowable << endl;
  */

  //create a row in the table
  ret += sid + " | ";
  ret += status + " | ";
  ret += sloan_period + " | ";
  ret += sfine_rate + " | ";
  ret += sreplacement_cost + " | ";
  ret += srenewable + " | ";
  ret += sborrowable + " | ";

  return ret;
}

void libitem::edit() {
  char choice;
  string admin_menu = "\ta. Edit the ID\n\tb. Edit the status\n\tc. Edit the fine rate\n\td. Edit the replacement costs\n\te. Edit the loan period.\n\tf. Edit the renewability.\n\tg. Edit the borrowability.\n\t";
  do {
    cout << admin_menu;
    cout << "\tWhat would you like to do? ";
    cin >> choice;

    if(cin.fail()) {
      cin.clear();
      cin.ignore(32767, '\n');
      choice = -1;
    }
  } while(choice < 'a' || choice > 'g');

  switch(choice) {
    case 'a':
      cout << "What would you like to change the id to? ";
      getline(cin, id);
      getline(cin, id);
      break;

    case 'b':
      cout << "What would you like to change the status to? ";
      getline(cin, status);
      getline(cin, status);
      break;

    case 'c':
      cout << "What would you like to change the fine rate to? ";
      cin >> fine_rate;
      break;

    case 'd':
      cout << "What would you like to change the replacement cost to? ";
      cin >> replacement_cost;
      break;

    case 'e':
      cout << "What would you like to change the loan period to (in days)? ";
      cin >> loan_period;
      loan_period = loan_period * 86400;
      break;

    case 'f':
      cout << "What would you like to change the renewability to (1 for true, 0 for false)? ";
      cin >> renewable;
      break;

    case 'g':
      cout << "What would you like to change the borrowability to (1 for true, 0 for false)? ";
      cin >> borrowable;
      break;
  }

  cout << "Sucessfully changed. Printing Item Details\n";
}

ostream & operator << (ostream & output, libitem * l) {
  l->print();
  return output;
}

istream & operator >> (istream & input, libitem * l) {
  l->edit();
  return input;
}
