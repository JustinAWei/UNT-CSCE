/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 1040
Instructor: Keathly
Description: A class that handles set/get of the patron structure
*/
#ifndef PATRON_H
#define PATRON_H
#include <string>
#include <iostream>
using namespace std;

class patron {
  private:
    int patron_id, num_borrowed;
    string name, status, address, phone;
    float fine;
    patron * prev, * next;

  public:
    /*
    Name: patron constuctor
    Parameters: None
    Returns: None
    Description:
    */
    patron();

    /*
    Name: print
    Parameters: None
    Returns: None
    Description: prints the patron details
    */
    void print();

    /*
    Name: set id
    Parameters: int
    Returns: None
    Description: setter for the patron's id
    */
    void set_id(int);

    /*
    Name: set num_borrowed
    Parameters: int
    Returns: None
    Description:setter for the patron's num_borrowed
    */
    void set_num_borrowed(int);

    /*
    Name: set name
    Parameters: string
    Returns: None
    Description:setter for the patron's name
    */
    void set_name(string);

    /*
    Name:set status
    Parameters: string
    Returns: None
    Description:setter for the patron's status
    */
    void set_status(string);

    /*
    Name:set address
    Parameters: string
    Returns: None
    Description:setter for the patron's address
    */
    void set_address(string);

    /*
    Name: set phone
    Parameters: string
    Returns: None
    Description:setter for the patron's phone
    */
    void set_phone(string);

    /*
    Name:set fine
    Parameters: float
    Returns: None
    Description:setter for the patron's fine
    */
    void set_fine(float);

    /*
    Name: next
    Parameters: patron*
    Returns: None
    Description:setter for the patron's next
    */
    void set_next(patron * );

    /*
    Name: set prev
    Parameters: patron*
    Returns: None
    Description:setter for the patron's prev
    */
    void set_prev(patron * );


    /*
    Name: get id
    Parameters: None
    Returns: int
    Description: getter for the patron's id
    */
    int get_id();

    /*
    Name: get num_borrowed
    Parameters: None
    Returns: int
    Description:getter for the patron's num_borrowed
    */
    int get_num_borrowed();

    /*
    Name:get_name
    Parameters: None
    Returns: string
    Description:getter for the patron's name
    */
    string get_name();

    /*
    Name:get_status
    Parameters: None
    Returns: string
    Description:getter for the patron's status
    */
    string get_status();

    /*
    Name:get_address
    Parameters: None
    Returns: string
    Description: getter for the patron's address
    */
    string get_address();

    /*
    Name:get_phone
    Parameters: None
    Returns: string
    Description:getter for the patron's phone
    */
    string get_phone();

    /*
    Name:get_fine
    Parameters: None
    Returns: float
    Description:getter for the patron's fine
    */
    float get_fine();

    /*
    Name:get next
    Parameters: None
    Returns: patron*
    Description:getter for the patron's next
    */
    patron * get_next();

    /*
    Name:get_prev
    Parameters: None
    Returns: patron*
    Description:getter for the patron's prev
    */
    patron * get_prev();


    /*
    Name:add_fine
    Parameters: float
    Returns: None
    Description: adds to the patron's fine and sets the status accordingly
    */
    void add_fine(float);

    /*
    Name:add_book_cost
    Parameters: float
    Returns: None
    Description: adds a book cost to the patron's fine and sets the status accordingly
    */
    void add_book_cost(float);

    /*
    Name:pay_fine
    Parameters: float
    Returns: None
    Description: subtracts a fine to the patron's fine and sets the status accordingly
    */
    void pay_fine(float);

};

#endif
