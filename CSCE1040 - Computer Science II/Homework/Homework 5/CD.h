/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to define the CD class.
*/

#ifndef CD_h
#define CD_h

#include <iostream>
#include <string>
#include <vector>

#include "libitem.h"

using namespace std;

class CD: public libitem {
  private: string artist,
  label;

  public:

  //Constructors
  CD();
  CD(string);

  //Getters
  string get_artist();
  string get_label();
  string get_attributes();
  //Setters
  void set_artist(string);
  void set_label(string);

  void print();
  void edit();

  friend istream & operator >> (istream & , CD * );
};
#endif
