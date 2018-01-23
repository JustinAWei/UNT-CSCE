/*
Email: JustinWei@my.unt.edu
Name: Justin Wei
Course: CSCE 1040
Instructor: Keathly
Description: A class that controls many patron structures.
*/

#ifndef PATRONS_H
#define PATRONS_H
#include <string>
#include <iostream>
#include "patron.h"
using namespace std;

class patrons {
  private:
    int count, id;
    patron *head, *tail;

  public:

    /*
    Name: pay_fine
    Parameters: None
    Returns: None
    Description: records that a patron has paid his/her fines
   */
    void pay_fine();

    /*
    Name: get_id
    Parameters: None
    Returns: int
    Description: return a unique id number
   */
    int get_id();

    /*
    Name: get_head
    Parameters: None
    Returns: patron*
    Description: return a the head of the linked list
   */
    patron* get_head();

    /*
    Name:patrons constructor
    Parameters: None
    Returns: None
    Description: inializes count, head and tail
    */
    patrons();

    /*
    Name: patrons destructor
    Parameters: None
    Returns: None
    Description: destorys all patrons in the linked list
    */
    ~patrons();

    /*
    Name: print mailing
    Parameters: None
    Returns: None
    Description: prints all patron names and addresses
    */
    void print_mailing();

    /*
    Name: print
    Parameters: None
    Returns: None
    Description: prints all patrons
    */
    void print();

    /*
    Name: print fines
    Parameters: None
    Returns: None
    Description: prines all patrons with excessive fines
    */
    void print_fines();

    /*
    Name: get count
    Parameters: None
    Returns: int
    Description: gets the count variable
    */
    int get_count();

    /*
    Name: add patron
    Parameters: None
    Returns: None
    Description: adds a patron to the linked list
    */
    void add_patron();


    /*
    Name: add patron
    Parameters: a patron
    Returns: None
    Description: adds a patron to the linked list
    */
    void add_patron(patron*);

    /*
    Name: remove patron
    Parameters: None
    Returns: None
    Description: removes a patron with a specific id from the linked list
    */
    void remove_patron();

    /*
    Name: edit patron
    Parameters: None
    Returns: None
    Description: edits the specified patron's value
    */
    void edit_patron();

    /*
    Name: find patron
    Parameters: int for the patron id
    Returns: patron*
    Description: gets the patron class with the specified id
    */
    patron *find_patron(int);
};
#endif
