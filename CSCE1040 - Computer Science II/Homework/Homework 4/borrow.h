/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 1040
Instructor: Keathly
Description: A class that handles set/get of the borrow structure
*/
#ifndef BORROW_H
#define BORROW_H
#include <string>
#include <iostream>
#include <time.h>
using namespace std;

class borrow {
  private:
    int trans_id, book_id, patron_id;
    time_t due;
    bool recheck;
    borrow* prev,* next;

  public:
    /*
    Name: borrow constructor
    Parameters: None
    Returns: None
    Description: initializes varilables
   */
    borrow();

    /*
    Name: set_next
    Parameters: borrow*
    Returns: None
    Description: setter for the borrow's next
   */
    void set_next(borrow* );

    /*
    Name:set_prev
    Parameters: borrow*
    Returns: None
    Description:setter for the borrow's prev
   */
    void set_prev(borrow* );


    /*
    Name:set_recheck
    Parameters: bool
    Returns: None
    Description:setter for the borrow's recheck
   */
    void set_recheck(bool);


    /*
    Name: set_trans_id
    Parameters: int
    Returns: None
    Description:setter for the borrow's trans_id
   */
    void set_trans_id(int);

    /*
    Name:set_book_id
    Parameters: int
    Returns: None
    Description:setter for the borrow's book_id
   */
    void set_book_id(int);

    /*
    Name:set_patron_id
    Parameters: int
    Returns: None
    Description:setter for the borrow's patron_id
   */
    void set_patron_id(int);

    /*
    Name: set_due
    Parameters: int
    Returns: None
    Description:setter for the borrow's set_due
   */
    void set_due(time_t);


    /*
    Name:get_recheck
    Parameters: None
    Returns: bool
    Description:getter for the borrow's recheck
   */
    bool get_recheck();

    /*
    Name: get_next
    Parameters: None
    Returns: borrow*
    Description:getter for the borrow's next
   */
    borrow* get_next();

    /*
    Name:get_prev
    Parameters: None
    Returns: borrow*
    Description:getter for the borrow's prev
   */
    borrow* get_prev();

    /*
    Name: get_trans_id
    Parameters: None
    Returns: int
    Description: getter for the borrow's trans_id
   */
    int get_trans_id();

    /*
    Name:get_book_id
    Parameters: None
    Returns: int
    Description:getter for the borrow's book_id
   */
    int get_book_id();

    /*
    Name:get_patron_id
    Parameters: None
    Returns: int
    Description:getter for the borrow's patron_id
   */
    int get_patron_id();

    /*
    Name:get_due
    Parameters: None
    Returns: int
    Description:getter for the borrow's due
   */
    time_t get_due();

    /*
    Name:print
    Parameters: None
    Returns: None
    Description: prints the borrow objects' details
   */
    void print();
};


#endif
