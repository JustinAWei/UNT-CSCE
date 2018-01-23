
/*
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to define the patrons class.
*/

#ifndef patrons_h
#define patrons_h

#include "patron.h"

using namespace std;

class patrons {
  private:
  int id_count;
  vector < patron > roster;

  public:

  //Constructors
  patrons();
  ~patrons();

  //Getters
  int get_id_count();
  int get_count();

  //Print
  void print_mailing();
  void print();
  void print_fines();

  //Patron Functions
  void add();
  void add(patron);
  void remove();
  void edit();
  void pay_fine();

  //find
  patron & find(int);
  bool in (int id);

  //Save / Load
  void save_patrons(FILE * );
  void load_patrons(ifstream & );

  //Overloads
  friend ostream & operator << (ostream & output, patrons * ps);
  friend istream & operator >> (istream & , patrons * ps);

};
#endif
