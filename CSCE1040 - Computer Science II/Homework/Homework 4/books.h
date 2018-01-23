/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 1040
Instructor: Keathly
Description: A class that controls many book structures.
*/

#ifndef BOOKS_H
#define BOOKS_H
#include <string>
#include <iostream>
#include "book.h"
#include "patrons.h"

using namespace std;

class borrows;
class books {
private:
  book* head, *tail;
  int count, id;

public:
  /*
  Name: get_head
  Parameters: None
  Returns: book*
  Description: return a the head of the linked list
 */
  book* get_head();

  /*
  Name: books constructor
  Parameters: None
  Returns: None
  Description: initializes the books variables
 */
  books();

  /*
  Name:books destructor
  Parameters: None
  Returns: None
  Description: destroys all books in the linked list
 */
  ~books();

  /*
  Name: get_count
  Parameters: None
  Returns: int
  Description: return the amount of books in the list
 */
  int get_count();


  /*
  Name: get_id
  Parameters: None
  Returns: int
  Description: return a unique id number
 */
  int get_id();

  /*
  Name:remove_book
  Parameters: None
  Returns: None
  Description: removes a book with a specified bookid
  */
  void remove_book();

  /*
  Name:add_book
  Parameters: None
  Returns: None
  Description: adds a book to the list
 */
  void add_book();

  /*
  Name:add_book
  Parameters: a book object
  Returns: None
  Description: adds a book to the list
 */
  void add_book(book*);

  /*
  Name: edit_book
  Parameters: None
  Returns: None
  Description: edits a book object
 */
  void edit_book();

  /*
  Name:find_book
  Parameters: int
  Returns: book*
  Description: finds and returns a book object with a specified id
 */
  book* find_book(int);

  /*
  Name: lose
  Parameters: patrons and borrows controllers
  Returns: None
  Description: marks a book as lost
 */
  void lose(patrons* ps, borrows* bw);

  /*
  Name: print
  Parameters: None
  Returns: None
  Description: prints all book sin linked list
 */
  void print();

};


#endif
