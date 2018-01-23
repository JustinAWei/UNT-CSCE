/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to implement the CD class.
*/

#include "CD.h"

using namespace std;

CD::CD() {
  type = "CD";
  renewable = false;
  loan_period = 172800;
}

CD::CD(string s): libitem() {
  type = "CD";
  id = s;
}

void CD::edit() {
  cout << "What is the label of the CD?\n";
  getline(cin, label);
  getline(cin, label);

  cout << "Who is the artist of the CD?\n";
  getline(cin, artist);
}

//Getters
string CD::get_artist() {
  return artist;
}
string CD::get_label() {
  return label;
}

//returns a row with attributes
string CD::get_attributes() {
  string ret = libitem::get_attributes();
  ret += artist + " | ";
  ret += label + " | ";
  return ret;
}

//Setters
void CD::set_artist(string s) {
  artist = s;
}
void CD::set_label(string s) {
  label = s;
}

void CD::print() {
  libitem::print();
  cout << "Label: " << label << endl;
  cout << "Artist: " << artist << endl << endl;
}

istream & operator >> (istream & i, CD * c) {

  string label, artist;
  float fine_rate, replacement_cost;

  cout << "What is the label of the CD?\n";
  getline(cin, label);
  getline(cin, label);

  cout << "Who is the artist of the CD?\n";
  getline(cin, artist);

  cout << "What is the fine rate of this CD? ";
  cin >> fine_rate;

  cout << "What is the replacement cost of this CD? ";
  cin >> replacement_cost;

  c->set_label(label);
  c->set_artist(artist);
  c->set_fine_rate(fine_rate);
  c->set_replacement_cost(replacement_cost);

  return i;
}
