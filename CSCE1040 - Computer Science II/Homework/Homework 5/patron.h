
/*
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to define the patron class.
*/

#ifndef patron_h
#define patron_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class patron {
  private:
  int patron_id, num_books, num_avs;
  string name, status, address, phone;
  float fine;

  public:

  //Constructors
  patron(int);
  patron();

  //Setters
  void set_id(int);
  void set_num_books(int);
  void set_num_avs(int);
  void set_name(string);
  void set_status(string);
  void set_phone(string);
  void set_address(string);
  void set_fine(float);

  //Getters
  int get_id();
  int get_num_books();
  string get_name();
  string get_status();
  string get_address();
  string get_phone();
  float get_fine();
  int get_num_avs();

  //Add / Pay Fines
  void add_fine(float);
  void pay_fine(float);

  //Print
  void print();

  //Checks
  bool check_fine();
  bool check_limit(string type);

  //Overloads
  friend ostream & operator << (ostream & , patron);
  friend istream & operator >> (istream & , patron & );

};
#endif
