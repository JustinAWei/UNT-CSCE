/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to define the reference class.
*/

#ifndef reference_h
#define reference_h

#include <iostream>
#include <string>
#include <vector>

#include "libitem.h"

using namespace std;

class reference: public libitem {
  private: string title,
  author,
  editor,
  publisher;

  public:

  //Constructors
  reference();
  reference(string);

  //Getters
  string get_title();
  string get_author();
  string get_editor();
  string get_publisher();
  string get_attributes();

  //Setters
  void set_title(string);
  void set_author(string);
  void set_editor(string);
  void set_publisher(string);


  //Print
  void print();

  //Fuctions
  void edit();

  //Overloads
  friend istream & operator >> (istream & , reference * );

};
#endif
