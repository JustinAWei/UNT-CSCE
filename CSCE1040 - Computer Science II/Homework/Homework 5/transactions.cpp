/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to implement the transactions class.
*/

#include "transactions.h"
#include <fstream>
#include <iostream>

using namespace std;

//Constructors
transactions::transactions(patrons * p, libitems * l) {
  ps = p;
  ls = l;
  id_count = 1;
}

transactions::~transactions() {
  vector < transaction > ().swap(list);
}

//Getters
int transactions::get_id_count() {
  return id_count;
}

void transactions::lose() {

  char p_lost;
  cout << "Is a patron recording an item as lost? (y/n) ";
  cin >> p_lost;

  if (p_lost == 'y') {

    int id;
    cout << "What is the transaction ID? ";
    cin >> id;

    transaction & t = find(id);
    libitem * l = ls->find(t.get_item_id());
    patron & p = ps->find(t.get_patron_id());

    /*
    //Print details of everything before checkout
    cout << t;
    cout << l;
    cout << p;
    */

    //delete the transaction
    remove(id);

    //add fine to patron
    p.add_fine(l->get_replacement_cost());

    //set status of item to lost
    l->set_status("LOST");
    cout << l;
    cout << p;
  } else {
    string item_id;
    cout << "What is the item ID? ";
    cin >> item_id;

    libitem * l = ls->find(item_id);

    //set status of item to lost
    l->set_status("LOST");

    //print details
    cout << l;
  }
}

void transactions::print_patrons_with_overdue() {
  cout << "Printing all patrons with overdue items.\n";

  for (int i = 0; i < list.size(); i++) {
    //if transaction is overdue and patron exists, print
    if (list[i].is_overdue() && ps->in (list[i].get_patron_id())) {
      ps->find(list[i].get_patron_id()).print();
    }
  }
}

void transactions::renew() {
  int id;
  cout << "What is the ID of the transaction you wish to renew? ";
  cin >> id;
  renew(id);
}

void transactions::renew(int id) {
  //check exists
  if ( in (id)) {
    transaction & t = find(id);

    //check renewable
    if (t.is_renewable()) {
      //extend due date
      t.set_due(t.get_due() + ls->find(t.get_item_id())->get_loan_period());

      //record renewed
      t.renew();

      //print details
      cout << t;
    } else {
      cout << "Transaction is not renewable.\n";
    }
  } else {
    cout << "Transaction does not exist.\n";
  }
}

void transactions::add(transaction t) {
  //add to vector
  list.push_back(t);

  //add to id count
  id_count++;

  //print details
  cout << t;
}

void transactions::check_out() {
  transaction t;
  //ensure patron and item exists
  if (ps->in (t.get_patron_id()) && ls->in (t.get_item_id())) {
    libitem * l = ls->find(t.get_item_id());
    patron & p = ps->find(t.get_patron_id());

    //ensure item is available
    if (!(l->is_borrowable())) {
      cout << "Item is not borrowable.\n";
      return;
    }

    //ensure patron does not have overdue books
    //ensure patron does not have fines
    //ensure patron will not exceed checkout limit
    if (l->get_status() != "IN" || !(check_patron_has_overdue(p.get_id()) && p.check_fine() && p.check_limit(l->get_type()))) {
      cout << "Patron or Item does not have correct status.\n";
      return;
    }

    //all conditions have been met, proceed with checking out book

    //set due date
    t.set_due(time(0) + l->get_loan_period());
    //set renewable chance
    t.set_renewable(l->is_renewable());
    //set id of transaction
    t.set_id(id_count++);

    //add one to the quantity of items checked out by patron
    if (l->get_type() == "Book") {
      p.set_num_books(p.get_num_books() + 1);
    } else {
      p.set_num_avs(p.get_num_avs() + 1);
    }

    //set status of item to out
    l->set_status("OUT");

    //add transactions to the list
    list.push_back(t);
    cout << t;

  } else {
    cout << "The patron or the item does not exist.\n";
    return;
  }
}

int transactions::check_patron_has_overdue(int id) {
  int count = 0;

  //count the number of overdue books
  if ( in (id)) {
    for (int i = 0; i < list.size(); i++) {
      if (list[i].is_overdue() && list[i].get_patron_id() == id) {
        count++;
      }
    }
  }
  return (count == 0) ? true : false;
}

void transactions::remove() {
  //prompt for id
  int id;
  cout << "What is the id of the transaction you wish to remove?\n";
  cin >> id;

  remove(id);
}

void transactions::remove(int id) {

  if ( in (id)) {
    transaction & t = find(id);
    if (ls->in (t.get_item_id()) && ps->in (t.get_patron_id())) {
      libitem * l = ls->find(t.get_item_id());
      patron & p = ps->find(t.get_patron_id());
      //set book to in
      l->set_status("IN");

      //add fines to patron if overdue
      if (t.is_overdue()) {
        //fine = days_overdue * fine_rate
        int days_overdue = static_cast < int > (time(0) - t.get_due() / 86400);
        p.add_fine(days_overdue * l->get_fine_rate());
      }

      //minus one from appropriate num borrowed
      if (l->get_type() == "Book") {
        p.set_num_books(p.get_num_books() - 1);
      } else {
        p.set_num_avs(p.get_num_avs() - 1);
      }

      //erase transaction
      for (vector < transaction > ::iterator it = list.begin(); it != list.end(); it++) {
        if (it->get_id() == id) {
          list.erase(it);
          return;
        }
      }
      //if failed to erase
      cout << "Could not erase for some reason.\n";

    } else {
      cout << "Patron or item does not exist.\n";
    }
  } else {
    cout << "Transaction does not exist.\n";
  }
}

void transactions::print_patron_checked_out() {

  int id;
  cout << "What is the id of the patron you wish to print the items of? ";
  cin >> id;
  cout << "Printing all items checked out by patron " << id << ":\n";

  for (int i = 0; i < list.size(); i++) {
    //if transaction contains patron, print the item.
    if (list[i].get_patron_id() == id && ls->in (list[i].get_item_id())) {
      ls->find(list[i].get_item_id())->print();
    }
  }
}

void transactions::print_overdue_items() {
  cout << "Printing Overdue Items:\n";
  for (int i = 0; i < list.size(); i++) {
    //if transaction is overdue and item exists
    if (list[i].is_overdue() && ls->in (list[i].get_item_id())) {
      ls->find(list[i].get_item_id())->print();
    }
  }
}

bool transactions:: in (int id) {
  //check if transaction exists
  for (int i = 0; i < list.size(); i++) {
    if (list[i].get_id() == id) {
      return i + 1;
    }
  }
  return 0;
}

transaction & transactions::find(int id) {
  //finds the transaction and returns it
  for (int i = 0; i < list.size(); i++) {
    if (list[i].get_id() == id) {
      return list[i];
    }
  }
}

void transactions::save_transactions(FILE * fout) {
  int N = list.size();

  //write number of objects
  fprintf(fout, "%d\n", N);

  //write column headers
  fprintf(fout, "Transaction ID | Patron ID | Item ID | Due | Renewable |\n");

  //for each obj print info
  for (int i = 0; i < N; i++) {
    int id, patron_id;
    string item_id;
    time_t due;
    bool renewable;

    id = list[i].get_id();
    patron_id = list[i].get_id();
    item_id = list[i].get_item_id();
    due = list[i].get_due();
    renewable = list[i].is_renewable();

    fprintf(fout, "%d | %d | %s | %ld | %d |\n", id, patron_id, item_id.c_str(), due, renewable);
  }
  fprintf(fout, "\n");
}

void transactions::load_transactions(ifstream & fin) {

  cout << "Loading transactions.\n";
  string s;
  //get the number of rows
  int N;
  fin >> N;

  //skip headers
  getline(fin, s, '\n');
  getline(fin, s, '\n');

  //loop through each row
  for (int n = 0; n < N; n++) {
    //cout << "COUNT " << n << endl;

    int id, pid, renewable;
    time_t due;
    string iid;

    fin >> id >> s;
    fin >> pid >> s;
    getline(fin, iid, '|');
    fin >> due >> s;
    fin >> renewable >> s;

    getline(fin, s);

    iid = iid.substr(1, iid.length() - 2);
    //create the object
    transaction t(id);

    t.set_patron_id(pid);
    t.set_item_id(iid);
    t.set_due(due);
    t.set_renewable(renewable);

    //add to list
    add(t);
  }

}

void transactions::print() {
  for (int i = 0; i < list.size(); i++) {
    cout << list[i];
  }
  return;
}

ostream & operator << (ostream & output, transactions * ts) {
  ts->print();
  return output;
}

istream & operator << (istream & input, transactions * ts) {
  ts->check_out();
  return input;
}
