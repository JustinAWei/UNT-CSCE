/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to implement the book class.
*/

#include "book.h"

using namespace std;

book::book() {
  type = "Book";
  loan_period = 1209600;
}

book::book(string s): libitem() {
  type = "Book";
  id = s;
}

void book::edit() {
  cout << "What is the new title of the book? ";
  getline(cin, title);
  getline(cin, title);

  cout << "Who is the new author of the book? ";
  getline(cin, author);

  cout << "Who is the new publisher of the book? ";
  getline(cin, publisher);
}

void book::print() {
  libitem::print();
  cout << "Title: " << title << endl;
  cout << "Author: " << author << endl;
  cout << "Publisher: " << publisher << endl << endl;
}

//Getters
string book::get_title() {
  return title;
}
string book::get_publisher() {
  return publisher;
}
string book::get_author() {
  return author;
}


string book::get_attributes() {
  //returns a row with attributes
  string ret = libitem::get_attributes();
  ret += title + " | ";
  ret += author + " | ";
  ret += publisher + " | ";
  return ret;
}

//Setters
void book::set_title(string s) {
  title = s;
}
void book::set_author(string s) {
  author = s;
}
void book::set_publisher(string s) {
  publisher = s;
}

istream & operator >> (istream & o, book * b) {
  string title, author, publisher;
  float fine_rate, replacement_cost;

  cout << "What is the title of the book? ";
  getline(cin, title);
  getline(cin, title);

  cout << "Who is the author of the book? ";
  getline(cin, author);

  cout << "who is the publisher of the book? ";
  getline(cin, publisher);

  cout << "What is the fine rate of this book? ";
  cin >> fine_rate;

  cout << "What is the replacement cost of this book? ";
  cin >> replacement_cost;

  b->set_title(title);
  b->set_author(author);
  b->set_publisher(publisher);
  b->set_fine_rate(fine_rate);
  b->set_replacement_cost(replacement_cost);
  return o;
}
