/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to define the DVD class.
*/

#ifndef DVD_h
#define DVD_h

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "libitem.h"

using namespace std;

class DVD: public libitem {
  private: string title,
  production_studio;
  int duration;

  public:

  //Constructors
  DVD();
  DVD(string);

  //Getters
  string get_title();
  string get_production_studio();
  string get_attributes();
  time_t get_duration();

  //Setters
  void set_production_studio(string);
  void set_title(string);
  void set_duration(time_t);

  void print();
  void edit();
  friend istream & operator >> (istream & , DVD * );

};
#endif
