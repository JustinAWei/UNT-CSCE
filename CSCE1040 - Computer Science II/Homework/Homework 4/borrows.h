/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 1040
Instructor: Keathly
Description: A class that controls many borrow structures.
*/

#ifndef BORROWS_H
#define BORROWS_H

#include <string>
#include <iostream>
#include "borrow.h"
#include "patrons.h"
#include "book.h"
#include "books.h"
using namespace std;

//every day a book is overdue, patron is charged $FINE_RATE
const int FINE_RATE = 1;

//a book is due CHECK_OUT_PERIOD seconds after check_out
const int CHECK_OUT_PERIOD = 1209600;

class borrows {
private:
  borrow *head, *tail;
  int id, count;
public:
  /*
  Name: get_head
  Parameters: None
  Returns: borrow*
  Description: return a the head of the linked list
 */
  borrow* get_head();

  /*
  Name: add_borrow
  Parameters: a borrow object and books and patrons controller
  Returns: none
  Description: adds a borrow object
 */
  void add_borrow(borrow* b, books* bs, patrons* ps);

  /*
  Name: calculate_fines
  Parameters: patrons controller
  Returns: none
  Description: updates all fine balances
 */
 void calculate_fines(patrons*);

  /*
  Name: print_overdue_patrons
  Parameters: the patron and book controllers
  Returns: none
  Description: prints all patrons with overdue books
 */
 void print_overdue_patrons(patrons*, books*);

  /*
  Name: print_patron_books
  Parameters: the patron and book controllers
  Returns: none
  Description: prints all of the books of a patron
 */
 void print_patron_books(patrons*, books*);

  /*
  Name: get_id
  Parameters: None
  Returns: int
  Description: return a unique id number
 */
  int get_id();

  /*
  Name: borrows constructor
  Parameters: None
  Returns: None
  Description: initializes borrows varilables
  */
  borrows();

  /*
  Name: borrows destructor
  Parameters: None
  Returns: None
  Description: deletes all borrow objects from linked list
  */
  ~borrows();


  /*
  Name: check_out
  Parameters: patrons*, books*
  Returns: None
  Description: checks out a book
  */
  void check_out(patrons*, books*);

  /*
  Name:find
  Parameters: two ints for the patronid and bookid
  Returns: None
  Description: find the borrow object with patronid and bookid
  */
  borrow* find(int, int);

  /*
  Name:check_in
  Parameters: patron and book ids and their respective controllers
  Returns: None
  Description: checks in the borrow object with the specified patron id and book id
  */
  void check_in(int p, int b, patrons* ps, books* bs);

  /*
  Name: get_count
  Parameters: None
  Returns: int
  Description: getter for the amount of borrows
  */
  int get_count();


  /*
  Name: print_overdue
  Parameters: patrons and books handlers
  Returns: None
  Description: prints all of the overdue books
  */
  void print_overdue(patrons*, books*);

  /*
  Name: print
  Parameters: None
  Returns: None
  Description: prints all of the borrow objects.
  */
  void print();

};


#endif
