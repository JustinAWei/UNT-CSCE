/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 1040
Instructor: Keathly
Description: A program to implement a library computer structure.
*/

#include <iostream>
#include <string>
#include <fstream>

#include "book.h"
#include "books.h"
#include "borrow.h"
#include "borrows.h"
#include "patron.h"
#include "patrons.h"
#include "main.h"
using namespace std;

//object controllers
patrons* ps = new patrons;
books* bs = new books;
borrows* bw = new borrows;

int main() {

  string menu = "    \n    a. Add a new library patron.    \n    b. Edit a patron's information.    \n    c. Remove a patron.    \n        \n    d. Add a new book to the catalog.    \n    e. Edit a book's information.    \n    f. Remove a book from the catalog.    \n        \n    g. Record a book as lost.    \n    h. Return a book.    \n    i. Check out a book.    \n        \n    j. Record that a patron has paid some money.    \n        \n    k. Print a list of all patrons.    \n    l. Print a list of all patrons with outstanding fines.    \n    m. Print a list of patrons with overdue books.    \n    n. Print a patron's checked out books.    \n    o. Print all overdue books, and who has them.    \n    p. Print address mailing labels.    \n    q. Load from a file.    \n    r. Save to a file.    \n    ";
  cout << "CSCE 1040  |  Homework 4  |  Justin Wei  | JustinWei@my.unt.edu  \n";

  //get current day for fine checking
  time_t cur = time(0);
  tm* last_check_date = localtime( & cur);

  char cont = -1;
  do {
    cout << menu << endl;

    //calculate_fines if a day has passed since we last calculated fines
    time_t cur = time(0);
    tm* current_day = localtime( & cur);

    //if there has been a change in the date, 
    if (current_day->tm_wday != last_check_date->tm_wday) {
      last_check_date = current_day;
      bw->calculate_fines(ps);
    }

    //prompt for choice
    char choice = 0;
    do {
      cout << "   What would you like to do? ";
      cin >> choice;

      if (cin.fail()) {
        cin.clear();
        cin.ignore(32676, '\n');
        choice = 0;
      }
    } while (choice < 'a' || choice > 'r');

    switch (choice) {
    case 'a':
      {
        //add new patron
        ps->add_patron();
        break;
      }
    case 'b':
      {
        //edit patron
        ps->edit_patron();
        break;
      }
    case 'c':
      {
        //remove patron
        ps->remove_patron();
        break;
      }
    case 'd':
      {
        //add book
        bs->add_book();
        break;
      }
    case 'e':
      {
        //edit book
        bs->edit_book();
        break;
      }
    case 'f':
      {
        //remove book
        bs->remove_book();
        break;
      }
    case 'g':
      {
        //record a book as lost
        bs->lose(ps, bw);
        break;
      }
    case 'h':
      {
        //returns a book
        int p, b;
        cout << "What is the id number of the patron? ";
        cin >> p;

        cout << "What is the id number of the book? ";
        cin >> b;

        bw->check_in(p, b, ps, bs);

        break;
      }
    case 'i':
      {
        bw->check_out(ps, bs);
        break;
      }

    case 'j':
      {
        //records that a patron has paid some of a fine
        ps->pay_fine();
        break;
      }
    case 'k':
      {
        //prints all patrons
        ps->print();
        break;
      }
    case 'l':
      {
        //prints all patrons with fines
        ps->print_fines();
        break;
      }

    case 'm':
      {
        //prints all patrons with overdue books
        bw->print_overdue_patrons(ps, bs);
        break;
      }
    case 'n':
      {
        //prints all books that a patron has checked out
        bw->print_patron_books(ps, bs);
        break;
      }
    case 'o':
      {
        //prints all overdue books
        bw->print_overdue(ps, bs);
        break;
      }

    case 'p':
      {
        //prints the mailing labels
        ps->print_mailing();
        break;
      }
    case 'q':
      {
        //Calls the load function
        load();
        break;
      }
    case 'r':
      {
        //Calls the save function
        save();
        break;
      }
    }

    //prompt to continue
    do {
      cout << "continue? (y/n)\n";
      cin >> cont;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(32676, '\n');
        cont = -1;
      }
    } while (cont != 'n' && cont != 'y');
  } while (cont != 'n');

  delete ps;
  delete bs;
  delete bw;
  return 0;
}

void load() {
  string file, s;
  //prompt for filename
  cout << "What is the name of the file you want to load from? ";
  cin >> file;
  ifstream fin(file.c_str());

  int N;
  fin >> N;

  //skip first line
  getline(fin, s);
  getline(fin, s);

  for (int n = 0; n < N; n++) {
    int id, num_borrowed;
    string name, address, phone, status, div;
    float fine;
    fin >> id >> div;

    //get all of the attributes
    getline(fin, name, '|');
    getline(fin, address, '|');
    getline(fin, phone, '|');
    getline(fin, status, '|');
    fin >> fine >> div;
    fin >> num_borrowed >> div;

    getline(fin, div);

    //remove padding
    name = name.substr(1, name.length() - 2);
    address = address.substr(1, address.length() - 2);
    phone = phone.substr(1, phone.length() - 2);
    status = status.substr(1, status.length() - 2);

    //create a patron object with attributes
    patron* p = new patron;
    p->set_id(id);
    p->set_name(name);
    p->set_address(address);
    p->set_phone(phone);
    p->set_status(status);
    p->set_fine(fine);
    p->set_num_borrowed(num_borrowed);

    //add to list
    ps->add_patron(p);

    printf("%d %s %s %s %s %f %d", id, name.c_str(), address.c_str(), phone.c_str(), status.c_str(), fine, num_borrowed);
  }

  fin >> N;
  //skip first line
  getline(fin, s);
  getline(fin, s);

  for (int i = 0; i < N; i++) {
    int id;
    string title, publisher, status, div;
    float cost;

    //get attributes
    fin >> id >> div;
    getline(fin, title, '|');
    getline(fin, publisher, '|');
    getline(fin, status, '|');
    fin >> cost >> div;
    getline(fin, div);

    //remove padding
    title = title.substr(1, title.length() - 2);
    publisher = publisher.substr(1, publisher.length() - 2);
    status = status.substr(1, status.length() - 2);

    //create book
    book* b = new book;
    b->set_book_id(id);
    b->set_title(title);
    b->set_publisher(publisher);
    b->set_status(status);
    b->set_cost(cost);

    //printf("%d %s %s %s %f\n", id, title.c_str(),publisher.c_str(),status.c_str(),cost);
    cout << endl;
    bs->add_book(b);
  }

  fin >> N;
  //skip first line
  getline(fin, s);
  getline(fin, s);

  for (int i = 0; i < N; i++) {
    int ti, bi, pi, recheck;
    time_t due;
    string div;

    //read attributes
    fin >> ti >> div;
    fin >> bi >> div;
    fin >> pi >> div;
    fin >> due >> div;
    fin >> recheck >> div;

    //use attr to create obj
    borrow* b = new borrow;
    b->set_trans_id(ti);
    b->set_book_id(bi);
    b->set_patron_id(pi);
    b->set_due(due);
    b->set_recheck(recheck);
    //printf("%d %d %d %lld\n", ti,bi,pi, (long long)due);

    //add obj to list
    bw->add_borrow(b, bs, ps);
  }
  fin.close();
}

void save() {
  string file;
  cout << "What is the name of the file you want to save to? ";
  cin >> file;
  ofstream fout(file.c_str());

  int N = ps->get_count();
  fout << N << endl;
  //print column headers
  fout << "ID | Name | Address | Phone | Status | Fine Balance | Num Borrowed |\n";

  patron* p = ps->get_head();
  for (int n = 0; n < N; n++) {
    //print each objs attr
    fout << p->get_id() << " | ";
    fout << p->get_name() << " | ";
    fout << p->get_address() << " | ";
    fout << p->get_phone() << " | ";
    fout << p->get_status() << " | ";
    fout << p->get_fine() << " | ";
    fout << p->get_num_borrowed() << " |" << endl;
    p = p->get_next();
  }

  N = bs->get_count();
  fout << endl << N << endl;
  //print column
  fout << "ID | Title | Publisher | Status | Cost |\n";
  book* b = bs->get_head();
  for (int i = 0; i < N; i++) {
    //print obj attr
    fout << b->get_book_id() << " | ";
    fout << b->get_title() << " | ";
    fout << b->get_publisher() << " | ";
    fout << b->get_status() << " | ";
    fout << b->get_cost() << " |" << endl;
    b = b->get_next();
  }

  N = bw->get_count();
  fout << endl << N << endl;
  //print column
  fout << "Transaction_ID | Book_ID | Patron_ID | Due Date | Renewable? |\n";
  borrow* bo = bw->get_head();
  for (int i = 0; i < N; i++) {
    if(bo == NULL) {
      cout << "NULL on " << i << endl;
      break;
    }
    //print obj attr
    fout << bo->get_trans_id() << " | ";
    fout << bo->get_book_id() << " | ";
    fout << bo->get_patron_id() << " | ";
    fout << bo->get_due() << " | ";
    fout << bo->get_recheck() << " |" << endl;
    bo = bo->get_next();
  }
}
