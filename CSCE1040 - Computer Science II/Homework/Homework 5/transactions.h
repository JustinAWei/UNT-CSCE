/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to define the transactions controller class.
*/

#ifndef transactions_h
#define transactions_h

#include "transaction.h"
#include "patrons.h"
#include "libitems.h"

using namespace std;

class transactions {
  private:
  int id_count;
  vector < transaction > list;
  patrons * ps;
  libitems * ls;

  public:

  //Constructors
  transactions(patrons * , libitems * );
  ~transactions();

  //Getters
  int get_id_count();

  //Transaction Functions
  void lose();
  void check_out();
  void remove();
  void remove(int id);
  void add(transaction);
  void renew();
  void renew(int);

  //Print
  void print();
  void print_patrons_with_overdue();
  void print_patron_checked_out();
  void print_overdue_items();

  //Find / In
  bool in (int id);
  transaction & find(int id);

  //Save / Load
  void load_transactions(ifstream & );
  void save_transactions(FILE * );

  //Checks
  int check_patron_has_overdue(int);

  //Overloads
  friend ostream & operator << (ostream & output, transactions * ts);
  friend istream & operator << (istream & input, transactions * ts);

};
#endif
