/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to define the transaction class.
*/

#ifndef transaction_h
#define transaction_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class transaction {
  private:
  int id, patron_id;
  string item_id;
  time_t due;
  bool renewable;

  public:

  //Constructors
  transaction();
  transaction(int);

  //Getters
  int get_id();
  int get_patron_id();
  string get_item_id();
  time_t get_due();
  bool is_renewable();
  bool is_overdue();

  //Setters
  void set_id(int);
  void set_patron_id(int);
  void set_item_id(string);
  void set_due(time_t);
  void set_renewable(bool);
  void renew();

  //print
  void print();

  //Overloads
  friend ostream & operator << (ostream & , transaction);
  friend istream & operator >> (istream & , transaction);
};
#endif
