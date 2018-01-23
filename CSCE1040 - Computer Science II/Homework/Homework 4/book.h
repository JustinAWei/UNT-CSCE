/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 1040
Instructor: Keathly
Description: A class that handles set/get of the book structure
*/
#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>

using namespace std;

class book {
  private:
    int book_id;
    string title, publisher, status;
    float cost;
    book *prev, *next;
  public:
    /*
    Name: book constuctor
    Parameters: None
    Returns: None
    Description:
    */
    book();

    /*
    Name: set_next
    Parameters: book*
    Returns: None
    Description: setter for book's next
    */
    void set_next(book *);
    /*
    Name: set_prev
    Parameters: book*
    Returns: None
    Description:setter for book's prev
    */
    void set_prev(book *);
    /*
    Name: book_id
    Parameters: int
    Returns: None
    Description:setter for book's id
    */
    void set_book_id(int);
    /*
    Name:set_title
    Parameters: string
    Returns: None
    Description:setter for book's title
    */
    void set_title(string);
    /*
    Name:set_publisher
    Parameters: string
    Returns: None
    Description:setter for book's publisher
    */
    void set_publisher(string);
    /*
    Name: set_status
    Parameters: string
    Returns: None
    Description:setter for book's status
    */
    void set_status(string);
    /*
    Name:cost
    Parameters: float
    Returns: None
    Description: setter for book's cost
    */
    void set_cost(float);

    /*
    Name: get_next
    Parameters: None
    Returns: book*
    Description: getter for book's next
    */
    book *get_next();
    /*
    Name: get_prev
    Parameters: None
    Returns: *book
    Description:getter for book's prev
    */
    book *get_prev();
    /*
    Name:get_book_id
    Parameters: None
    Returns: int
    Description:getter for book's id
    */
    int get_book_id();
    /*
    Name:get_title
    Parameters: None
    Returns: string
    Description:getter for book's title
    */
    string get_title();
    /*
    Name:get_publisher
    Parameters: None
    Returns: string
    Description:getter for book's publisher
    */
    string get_publisher();
    /*
    Name:get_status
    Parameters: None
    Returns: string
    Description:getter for book's status
    */
    string get_status();
    /*
    Name:get_cost
    Parameters: None
    Returns: float
    Description:getter for book's cost
    */
    float get_cost();
    /*
    Name:print
    Parameters: None
    Returns: None
    Description: prints the book's details
    */
    void print();
};

#endif
