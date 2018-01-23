/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to implement the reference class.
*/

#include "reference.h"

using namespace std;

//Constructors
reference::reference() {
  type = "Reference";
  borrowable = renewable = false;
  fine_rate = replacement_cost = 0;

}

reference::reference(string s): libitem() {
  type = "Reference";
  id = s;
}

void reference::edit() {
  cout << "Who is the author of the reference?\n";
  getline(cin, author);
  getline(cin, author);

  cout << "Who is the editor of the reference?\n";
  getline(cin, editor);

  cout << "who is the publisher of the reference?\n";
  getline(cin, publisher);
}

//Getters
string reference::get_title() {
  return title;
}
string reference::get_author() {
  return author;
}
string reference::get_editor() {
  return editor;
}
string reference::get_publisher() {
  return publisher;
}
string reference::get_attributes() {
    string ret = libitem::get_attributes();
    ret += title + " | ";
    ret += author + " | ";
    ret += publisher + " | ";
    ret += editor + " |";
    return ret;
  }
  //Setters
void reference::set_title(string s) {
  title = s;
}
void reference::set_author(string s) {
  author = s;
}
void reference::set_editor(string s) {
  editor = s;
}
void reference::set_publisher(string s) {
  publisher = s;
}

void reference::print() {
  libitem::print();
  cout << "Title: " << title << endl;
  cout << "Author: " << author << endl;
  cout << "Editor: " << editor << endl;
  cout << "Publisher: " << publisher << endl << endl;
}

istream & operator >> (istream & i, reference * r) {
  string title, author, editor, publisher;

  cout << "What is the title of the reference?\n";
  getline(cin, title);
  getline(cin, title);

  cout << "Who is the author of the reference?\n";
  getline(cin, author);

  cout << "Who is the editor of the reference?\n";
  getline(cin, editor);

  cout << "Who is the publisher of the reference?\n";
  getline(cin, publisher);

  r->set_title(title);
  r->set_author(author);
  r->set_editor(editor);
  r->set_publisher(publisher);

  return i;
}
