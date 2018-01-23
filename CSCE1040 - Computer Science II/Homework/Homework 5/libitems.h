/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Course: CSCE1040
Description: A program to define the libitems controller class.
*/

#ifndef libitems_h
#define libitems_h

#include "libitem.h"
#include <sstream>

using namespace std;

class libitems {
  private:
  int id_count;
  vector < libitem * > items;

  public:

  //Constructors
  libitems();
  ~libitems();
  int get_id_count();
  string generate_id();
  void print();
  void add(libitem * );
  void remove();
  void edit();
  libitem * find(string);
  bool in (string id);
  void admin_edit();

  void load_libitems(ifstream & );
  void load_books(ifstream & );
  void load_CDs(ifstream & );
  void load_DVDs(ifstream & );
  void load_references(ifstream & );

  void save_libitems(FILE * );
  void save_books(FILE * );
  void save_CDs(FILE * );
  void save_DVDs(FILE * );
  void save_references(FILE * );

  friend ostream & operator << (ostream & output, libitems * ls);
  friend istream & operator >> (istream & input, libitems * ls);
};
#endif
