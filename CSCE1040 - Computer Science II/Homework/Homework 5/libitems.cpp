/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to implement the libitems class.
*/

#include <fstream>
#include <iostream>
#include "libitems.h"
#include "CD.h"
#include "DVD.h"
#include "reference.h"
#include "book.h"

using namespace std;

libitems::libitems() {
  cout << "Constructing libitems!\n";
  id_count = 1;
}

libitems::~libitems() {
  cout << "Destroying libitems!\n";

  //deletes all pointers in vector
  for (int i = 0; i < items.size(); i++) {
    delete items[i];
  }

  //switches current items with empty one, deallocating all memory.
  vector<libitem*>().swap(items);
}

int libitems::get_id_count() {
  return id_count;
}

string libitems::generate_id() {

  string original_id;
  char orig;
  cout << "Is this a copy of an existing item? (y/n) ";
  cin >> orig;

  //adding a copy
  if (orig == 'y') {
    cout << "If adding a copy, type the id of an existing item: ";
    cin >> original_id;

    //append the copy_number onto the id if needed
    int copy_number = 2;
    string temp = original_id;

    //find an available number
    while ( in (temp)) {
      stringstream ss;
      ss << original_id << "c" << copy_number;
      ss >> temp;
      copy_number++;
    }
    original_id = temp;
  } else {
    //assign the next natural number as the id
    stringstream ss;
    ss << id_count;
    ss >> original_id;
  }
  return original_id;
}

bool libitems::in (string id) {

  //loop through the vector and find if item exists

  //cout << "Trying to find libitem with id |" << id << "|" << endl;
  for (int i = 0; i < items.size(); i++) {
    //cout << "|" << items[i]->get_id() << "|" << endl;
    if (items[i]->get_id() == id) {
      //cout << "Found.\n";
      return i + 1;
    }
  }
  //cout << "Not found.\n";
  return false;
}

libitem * libitems::find(string id) {

  //finds an item and returns it
  for (int i = 0; i < items.size(); i++) {
    if (items[i]->get_id() == id) {
      return items[i];
    }
  }
}

void libitems::print() {
  cout << "Printing all libitems.\n";
  for (int i = 0; i < items.size(); i++) {
    cout << items[i];
  }
}

void libitems::add(libitem * l) {

  //add item to vector
  items.push_back(l);

  //add one to id to keep unique ids
  id_count++;

  //print details of libitem
  cout << l;
}

void libitems::remove() {
  //prompt for id
  string id;
  cout << "What is the id of the item you wish to remove?\n";
  cin >> id;

  if ( in (id)) {
    libitem * p = find(id);

    //don't erase if out
    if (p->get_status() == "OUT") {
      cout << "Item with ID: " << p->get_id() << " is currently checked out.\n";
      return;
    }

    //erase it if standing is good
    items.erase(items.begin() + in (id) - 1);

  } else {
    cout << "Item does not exist.\n";
  }
}

void libitems::edit() {
  //prompt for id
  string id;
  cout << "What is the id of the libitem you wish to edit?\n";
  cin >> id;

  //found
  if (in (id)) {

    libitem * p = find(id);

    string s;
    cout << "\nEditing " << p->get_type() << " " << id << endl;
    p->edit();
    cout << "Sucessfully edited." << endl;

    //print details
    cout << p;
  } else {
    cout << "Item does not exist.\n";
  }
}

void libitems::admin_edit() {
  //prompt for id
  string id;
  cout << "What is the id of the libitem you wish to edit?\n";
  cin >> id;

  //found
  if (in(id)) {

    libitem * p = find(id);

    string s;
    cout << "\nEditing " << p->get_type() << " " << id << endl;

    //edit basic admin information
    p->libitem::edit();
    cout << "Sucessfully edited." << endl;

    //print details
    cout << p;
  } else {
    cout << "Item does not exist.\n";
  }
}

void libitems::save_libitems(FILE * fout) {
  cout << "Saving Libitems\n";
  save_books(fout);
  save_CDs(fout);
  save_DVDs(fout);
  save_references(fout);
}

void libitems::save_books(FILE * fout) {
  cout << "Saving Book\n";
  int N = 0;
  for (int i = 0; i < items.size(); i++) {
    if (items[i]->get_type() == "Book") {
      N++;
    }
  }
  fprintf(fout, "%d\n", N);

  //print column headers
  fprintf(fout, "Book ID | Status | Loan Period | Fine Rate | Replacement Cost | Renewable | Borrowable | Title | Author | Publisher |\n");

  for (int i = 0; i < items.size(); i++) {
    //cout << items[i]->get_type() << endl;
    //print details of all books
    if (items[i]->get_type() == "Book") {
      fprintf(fout, "%s\n", items[i]->get_attributes().c_str());
    }
  }
  fprintf(fout, "\n");
}

void libitems::save_CDs(FILE * fout) {
  cout << "Saving CDs\n";
  int N = 0;
  for (int i = 0; i < items.size(); i++) {
    if (items[i]->get_type() == "CD") {
      N++;
    }
  }

  //print number of books and column headers
  fprintf(fout, "%d\n", N);
  fprintf(fout, "CD ID | Status | Loan Period | Fine Rate | Replacement Cost | Renewable | Borrowable | Artist | Label |\n");

  for (int i = 0; i < items.size(); i++) {
    //cout << items[i]->get_type() << endl;
    //print cd details
    if (items[i]->get_type() == "CD") {
      fprintf(fout, "%s\n", items[i]->get_attributes().c_str());
    }
  }
  fprintf(fout, "\n");
}
void libitems::save_DVDs(FILE * fout) {
  cout << "Saving DVDs\n";
  int N = 0;
  for (int i = 0; i < items.size(); i++) {
    if (items[i]->get_type() == "DVD") {
      N++;
    }
  }
  //print quantity and column headers
  fprintf(fout, "%d\n", N);
  fprintf(fout, "DVD ID | Status | Loan Period | Fine Rate | Replacement Cost | Renewable | Borrowable | Title | Production Studio | Duration |\n");

  for (int i = 0; i < items.size(); i++) {
    //cout << items[i]->get_type() << endl;
    //print dvd details
    if (items[i]->get_type() == "DVD") {
      fprintf(fout, "%s\n", items[i]->get_attributes().c_str());
    }
  }
  fprintf(fout, "\n");
}
void libitems::save_references(FILE * fout) {
  cout << "Saving References\n";
  int N = 0;
  for (int i = 0; i < items.size(); i++) {
    if (items[i]->get_type() == "Reference") {
      N++;
    }
  }

  //print quantity and column headers
  fprintf(fout, "%d\n", N);
  fprintf(fout, "Reference ID | Status | Loan Period | Fine Rate | Replacement Cost | Renewable | Borrowable | Title | Author | Editor | Publisher |\n");

  for (int i = 0; i < items.size(); i++) {
    //cout << items[i]->get_type() << endl;
    //print reference details
    if (items[i]->get_type() == "Reference") {
      fprintf(fout, "%s\n", items[i]->get_attributes().c_str());
    }
  }
  fprintf(fout, "\n");
}

void libitems::load_libitems(ifstream & fin) {
  cout << "Loading Libitems\n";
  load_books(fin);
  load_CDs(fin);
  load_DVDs(fin);
  load_references(fin);
}

void libitems::load_books(ifstream & fin) {
  cout << "Loading books.\n";
  string s;
  //get the number of rows
  int N;
  fin >> N;

  //skip headers
  getline(fin, s, '\n');
  getline(fin, s, '\n');
  //cout << s;

  //cout << N << endl;

  //loop through each row
  for (int n = 0; n < N; n++) {
    //cout << "COUNT " << n << endl;

    string title, author, publisher, id, status;
    time_t loan_period;
    float fine_rate, replacement_cost;
    bool renewable, borrowable;

    //input attributes
    getline(fin, id, '|');
    getline(fin, status, '|');
    fin >> loan_period >> s;
    fin >> fine_rate >> s;
    fin >> replacement_cost >> s;
    fin >> renewable >> s;
    fin >> borrowable >> s;
    getline(fin, title, '|');
    getline(fin, author, '|');
    getline(fin, publisher, '|');

    getline(fin, s);

    //remove padding
    id = id.substr(0, id.length() - 1);
    title = title.substr(1, title.length() - 2);
    status = status.substr(1, status.length() - 2);
    author = author.substr(1, author.length() - 2);
    publisher = publisher.substr(1, publisher.length() - 2);

    //create the object
    book * b = new book(id);

    b->set_loan_period(loan_period);
    b->set_fine_rate(fine_rate);
    b->set_replacement_cost(replacement_cost);
    b->set_renewable(renewable);
    b->set_borrowable(borrowable);
    b->set_title(title);
    b->set_author(author);
    b->set_publisher(publisher);
    b->set_status(status);

    //add to list
    add(b);
    //printf("%s %ld %f %f %d %d %s %s %s\n", id.c_str(), loan_period, fine_rate, replacement_cost, renewable, borrowable, title.c_str(), author.c_str(), publisher.c_str());
  }
}

void libitems::load_CDs(ifstream & fin) {

  cout << "Loading CDs.\n";
  string s;
  //get the number of rows
  int N;
  fin >> N;

  //skip headers
  getline(fin, s, '\n');
  getline(fin, s, '\n');
  //cout << s;

  //cout << N << endl;

  //loop through each row
  for (int n = 0; n < N; n++) {
    //cout << "COUNT " << n << endl;

    //Variables
    string id, status, type, artist, label;
    time_t loan_period;
    float fine_rate, replacement_cost;
    bool renewable, borrowable;

    //get values from file
    getline(fin, id, '|');
    getline(fin, status, '|');
    fin >> loan_period >> s;
    fin >> fine_rate >> s;
    fin >> replacement_cost >> s;
    fin >> renewable >> s;
    fin >> borrowable >> s;
    getline(fin, artist, '|');
    getline(fin, label, '|');
    getline(fin, s);

    //remove padding
    id = id.substr(0, id.length() - 1);
    status = status.substr(1, status.length() - 2);
    artist = artist.substr(1, artist.length() - 2);
    label = label.substr(1, label.length() - 2);

    //create the object
    CD * l = new CD(id);

    l->set_loan_period(loan_period);
    l->set_fine_rate(fine_rate);
    l->set_replacement_cost(replacement_cost);
    l->set_renewable(renewable);
    l->set_borrowable(borrowable);
    l->set_artist(artist);
    l->set_label(label);
    l->set_status(status);
    //set the attributes

    add(l);
    //print
    //printf("|%s| %ld %f %f %d %d %s %s\n", id.c_str(), loan_period, fine_rate, replacement_cost, renewable, borrowable, artist.c_str(), label.c_str());
  }
}

void libitems::load_DVDs(ifstream & fin) {

  cout << "Loading DVDs.\n";
  string s;
  //get the number of rows
  int N;
  fin >> N;

  //skip headers
  getline(fin, s, '\n');
  getline(fin, s, '\n');
  //cout << s;

  //cout << N << endl;

  //loop through each row
  for (int n = 0; n < N; n++) {
    //cout << "COUNT " << n << endl;

    //Variables
    string id, status, type, artist, label;
    time_t loan_period, duration;
    float fine_rate, replacement_cost;
    bool renewable, borrowable;

    //get values from file
    getline(fin, id, '|');
    getline(fin, status, '|');
    fin >> loan_period >> s;
    fin >> fine_rate >> s;
    fin >> replacement_cost >> s;
    fin >> renewable >> s;
    fin >> borrowable >> s;
    getline(fin, artist, '|');
    getline(fin, label, '|');
    fin >> duration >> s;

    getline(fin, s);

    //remove padding
    id = id.substr(0, id.length() - 1);
    status = status.substr(1, status.length() - 2);
    artist = artist.substr(1, artist.length() - 2);
    label = label.substr(1, label.length() - 2);

    //create the object
    DVD * l = new DVD(id);

    l->set_loan_period(loan_period);
    l->set_fine_rate(fine_rate);
    l->set_replacement_cost(replacement_cost);
    l->set_renewable(renewable);
    l->set_borrowable(borrowable);
    l->set_title(artist);
    l->set_production_studio(label);
    l->set_duration(duration);
    l->set_status(status);
    //set the attributes

    add(l);
    //print
    //printf("|%s| %ld %f %f %d %d %s %s %ld\n", id.c_str(), loan_period, fine_rate, replacement_cost, renewable, borrowable, artist.c_str(), label.c_str(), duration);
  }
}

void libitems::load_references(ifstream & fin) {
  cout << "Loading references.\n";
  string s;
  //get the number of rows
  int N;
  fin >> N;

  //skip headers
  getline(fin, s, '\n');
  getline(fin, s, '\n');
  //cout << s;

  //cout << N << endl;

  //loop through each row
  for (int n = 0; n < N; n++) {
    //cout << "COUNT " << n << endl;

    string title, author, publisher, editor, id, status;
    time_t loan_period;
    float fine_rate, replacement_cost;
    bool renewable, borrowable;

    getline(fin, id, '|');
    getline(fin, status, '|');
    fin >> loan_period >> s;
    fin >> fine_rate >> s;
    fin >> replacement_cost >> s;
    fin >> renewable >> s;
    fin >> borrowable >> s;
    getline(fin, title, '|');
    getline(fin, author, '|');
    getline(fin, publisher, '|');
    getline(fin, editor, '|');

    getline(fin, s);

    //remove padding
    id = id.substr(0, id.length() - 1);
    status = status.substr(1, status.length() - 2);
    title = title.substr(1, title.length() - 2);
    author = author.substr(1, author.length() - 2);
    editor = editor.substr(1, editor.length() - 2);
    publisher = publisher.substr(1, publisher.length() - 2);

    //create the object
    reference * r = new reference(id);

    r->set_loan_period(loan_period);
    r->set_fine_rate(fine_rate);
    r->set_replacement_cost(replacement_cost);
    r->set_renewable(renewable);
    r->set_borrowable(borrowable);
    r->set_title(title);
    r->set_author(author);
    r->set_publisher(publisher);
    r->set_editor(editor);
    r->set_status(status);

    //add to list
    add(r);
    //printf("%s %ld %f %f %d %d %s %s %s %s\n", id.c_str(), loan_period, fine_rate, replacement_cost, renewable, borrowable, title.c_str(), author.c_str(), publisher.c_str(), editor.c_str());
  }
}

ostream & operator << (ostream & output, libitems * ls) {
  //print item details
  ls->print();
  return output;
}

istream & operator >> (istream & input, libitems * ls) {
  //libitem does not need insertion overload since it only has default values
  return input;
}
