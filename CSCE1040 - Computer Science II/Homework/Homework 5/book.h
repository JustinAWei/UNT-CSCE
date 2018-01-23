/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to define the book class.
*/

#ifndef book_h
#define book_h

#include <iostream>
#include <string>

#include "libitem.h"

using namespace std;

class book: public libitem {
  private: string title,
  author,
  publisher;

  public:

  //Constructors
  book();
  book(string);

  //Getters
  string get_title();
  string get_author();
  string get_publisher();
  string get_attributes();

  //Setters
  void set_title(string);
  void set_author(string);
  void set_publisher(string);

  void print();
  void edit();

  friend istream & operator >> (istream & o, book * b);

};
#endif
