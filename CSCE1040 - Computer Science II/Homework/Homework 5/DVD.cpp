/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to implement the DVD class.
*/

#include "DVD.h"

using namespace std;

DVD::DVD() {
  type = "DVD";
  renewable = false;
  loan_period = 172800;
}

DVD::DVD(string s): libitem() {
  type = "DVD";
  id = s;
}

void DVD::edit() {
  cout << "What is the title of the DVD?\n";
  getline(cin, title);
  getline(cin, title);

  cout << "What is the production studio of the DVD?\n";
  getline(cin, production_studio);

  cout << "What is the new duration of the DVD?\n";
  cin >> duration;
}

//Getters
string DVD::get_title() {
  return title;
}
string DVD::get_production_studio() {
  return production_studio;
}
time_t DVD::get_duration() {
  return duration;
}
string DVD::get_attributes() {
  string ret = libitem::get_attributes();
  stringstream ss;
  ss << duration;
  string sduration;
  ss >> sduration;

  ret += title + " | ";
  ret += production_studio + " | ";
  ret += sduration + " | ";
  return ret;
}

//Setters
void DVD::set_production_studio(string s) {
  production_studio = s;
}
void DVD::set_title(string s) {
  title = s;
}
void DVD::set_duration(time_t t) {
  duration = t;
}

void DVD::print() {
  libitem::print();
  cout << "Title: " << title << endl;
  cout << "Production Studio: " << production_studio << endl;
  cout << "Duration: " << duration << " minutes.\n" << endl << endl;
}

istream & operator >> (istream & i, DVD * d) {
  string title, production_studio;
  float fine_rate, replacement_cost;
  time_t duration;

  cout << "What is the title of the DVD?\n";
  getline(cin, title);
  getline(cin, title);

  cout << "What is the production studio of the DVD?\n";
  getline(cin, production_studio);

  cout << "What is the fine rate of this DVD? ";
  cin >> fine_rate;

  cout << "What is the replacement cost of this DVD? ";
  cin >> replacement_cost;

  cout << "What is the duration of the DVD in minutes? ";
  cin >> duration;

  d->set_title(title);
  d->set_production_studio(production_studio);
  d->set_fine_rate(fine_rate);
  d->set_replacement_cost(replacement_cost);
  d->set_duration(duration);

  return i;
}
