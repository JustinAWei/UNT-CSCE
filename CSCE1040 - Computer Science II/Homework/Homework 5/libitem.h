/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to define the libitem class.
*/

#ifndef libitem_h
#define libitem_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class libitem {
  protected:
  string id, status, type;
  time_t loan_period;
  float fine_rate, replacement_cost;
  bool renewable, borrowable;

  public:

  //Constructors
  libitem();

  //Getters
  bool is_renewable();
  bool is_borrowable();
  string get_id();
  string get_status();
  time_t get_loan_period();
  float get_fine_rate();
  float get_replacement_cost();
  string get_type();
  virtual string get_attributes();

  //Setters
  void set_id(string);
  void set_status(string);
  void set_loan_period(time_t);
  void set_fine_rate(float);
  void set_replacement_cost(float);
  void set_borrowable(bool);
  void set_renewable(bool);

  //print
  virtual void print();

  virtual void edit();

  //Overload
  friend ostream & operator << (ostream & , libitem * );
  friend istream & operator >> (istream & , libitem * );
};
#endif
