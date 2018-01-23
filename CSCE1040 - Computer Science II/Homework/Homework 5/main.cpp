/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to implement a library computer structure.
*/

//libraries
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

//header files
#include "book.h"
#include "CD.h"
#include "DVD.h"
#include "libitem.h"
#include "libitems.h"
#include "reference.h"
#include "patron.h"
#include "patrons.h"
#include "transaction.h"
#include "transactions.h"
#include "main.h"

//object controllers
libitems* ls = new libitems;
patrons* ps = new patrons;
transactions* ts = new transactions(ps, ls);

using namespace std;

int main() {
  char cont = -1;

  //menus
  string libitem_choices = "\ta. Book\n\tb. CD\n\tc. DVD\n\td. Reference\n";
  string menu = "    \n    a. Add a new library patron.    \n    b. Edit a patron's information.    \n    c. Remove a patron.    \n        \n    d. Add a new item to the catalog.    \n    e. Edit an item's information.    \n    f. Remove an item from the catalog.    \n        \n    g. Record an item as lost.    \n    h. Return an item.    \n    i. Check out an item.    \n\tt. Renew an item.        \n\n    j. Record that a patron has paid some money.    \n        \n    k. Print a list of all patrons.    \n    l. Print a list of all patrons with outstanding fines.    \n    m. Print a list of patrons with overdue items.    \n    n. Print a patron's checked out items.    \n\n    o. Print all overdue items, and who has them.    \n    p. Print address mailing labels.    \n    q. Load from a file.    \n    r. Save to a file.    \n    s. Admin Menu\n\n    u. PRINT ALL ITEMS.\n    v. PRINT ALL TRANSACTIONS.\n\n";

  //program runtime header
  cout << "CSCE 1040 | Homework 5 | Justin Wei | JustinWei@my.unt.edu\n";

  do {
    //print the menu
    cout << menu;
    char choice = prompt_choice('a', 'v', "What would you like to do?");

    switch (choice) {

      //Add, Edit, Remove Patrons
    case 'a':
      {
        cin >> ps;
        break;
      }
    case 'b':
      {
        ps->edit();
        break;
      }
    case 'c':
      {
        ps->remove();
        break;
      }

      //Add, Edit, Remove Items
    case 'd':
      {
        cout << libitem_choices;
        switch (prompt_choice('a', 'd', "Which item type would you like to add? ")) {

          //Choose type of item to add.
        case 'a':
          {
            book * l = new book;
            cin >> l;
            l->set_id(ls->generate_id());
            ls->add(l);
            break;
          }
        case 'b':
          {
            CD * l = new CD;
            cin >> l;
            l->set_id(ls->generate_id());
            ls->add(l);
            break;
          }
        case 'c':
          {
            DVD * l = new DVD;
            cin >> l;
            l->set_id(ls->generate_id());
            ls->add(l);
            break;
          }
        case 'd':
          {
            reference * l = new reference;
            cin >> l;
            l->set_id(ls->generate_id());
            ls->add(l);
            break;
          }
        }
        break;
      }
    case 'e':
      {
        ls->edit();
        break;
      }
    case 'f':
      {
        ls->remove();
        break;
      }

      //check out, renew, return, and lose a book.
    case 'g':
      {
        ts->lose();
        break;
      }
    case 'h':
      {
        ts->remove();
        break;
      }
    case 'i':
      {
        ts->check_out();
        break;
      }

      //pay fines
    case 'j':
      {
        ps->pay_fine();
        break;
      }

      //print...

      //all patons
    case 'k':
      {
        cout << ps;
        break;
      }

      //all patorns with fines
    case 'l':
      {
        ps->print_fines();
        break;
      }

      //all patrons with overdue items
    case 'm':
      {
        ts->print_patrons_with_overdue();
        break;
      }

      //all items from a patron
    case 'n':
      {
        ts->print_patron_checked_out();
        break;
      }

      //all overdue items
    case 'o':
      {
        ts->print_overdue_items();
        break;
      }

      //mailing labels
    case 'p':
      {
        ps->print_mailing();
        break;
      }

      //save/load
    case 'q':
      {
        load();
        break;
      }
    case 'r':
      {
        save();
        break;
      }

      //admin menu
    case 's':
      {
        do {
          ls->admin_edit();
        } while (prompt_continue());
        cout << "Exiting out of admin menu, would you like to continue with the main menu?\n";
        break;
      }

    //renew
    case 't':
      {
        ts->renew();
        break;
      }

      //print all libitems
    case 'u':
      {
        cout << ls;
        break;
      }
      //print all transactions
    case 'v':
      {
        cout << ts;
        break;
      }

    }

    //prompt to continue
  } while (prompt_continue());

  //clean up
  delete ls;
  delete ps;
  delete ts;
  return 0;
}

char prompt_choice(char upb, char lowb, string prompt) {
  //prompt for choice
  char
  var = 0;
  do {
    cout << "   What would you like to do? ";
    cin >>
      var;

    //error checking
    if (cin.fail()) {
      cin.clear();
      cin.ignore(32676, '\n');
      var = 0;
    }
  } while (var < upb ||
    var > lowb);
  return var;
}

bool prompt_continue() {
  char cont;
  do {
    cout << "continue? (y/n)\n";
    cin >> cont;

    //error checking
    if (cin.fail()) {
      cin.clear();
      cin.ignore(32676, '\n');
      cont = -1;
    }
  } while (cont != 'n' && cont != 'y');
  return cont == 'y';
}

void save() {
  string file;
  //prompt for filename
  cout << "What is the name of the file you want to save to? ";
  cin >> file;
  FILE * fout = fopen(file.c_str(), "w");
  //cout << file << endl;

  //Error checking
  if (fout == NULL) {
    cout << "ERROR OPENING FILE\n";
    exit(1);
  }

  ps->save_patrons(fout);
  ls->save_libitems(fout);
  ts->save_transactions(fout);
  fclose(fout);
  cout << "Successfully saved data to " << file << endl;
}

void load() {
  string file;
  //prompt for filename
  cout << "What is the name of the file you want to load from? ";
  cin >> file;
  ifstream fin(file.c_str());
  //cout << file << endl;

  //Error checking
  if (fin == NULL) {
    cout << "ERROR OPENING FILE\n";
    exit(1);
  }

  ps->load_patrons(fin);
  ls->load_libitems(fin);
  ts->load_transactions(fin);

  fin.close();

  cout << "Successfully loaded data from " << file << endl;
}
