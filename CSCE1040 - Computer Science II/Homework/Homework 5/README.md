### ALGORITHM DESIGN
```c++
MAIN
  char prompt_choice(char upb, char lowb, string prompt);
    display prompt
    prompts for a choice between character upb and lowb
    while char is between the range
  bool prompt_continue();
    display "continue? (yes no)"
    prompts for a character
    while char is not y or n

  //Save / Load
  void save();
    calls save patrons, transactions, libitems
  void load();
    calls load patrons, transactions, libitems

PATRON
  Basic Get / Set
  //Add / Pay Fines
  void add_fine(float);
    add fines and sets status appropriately
  void pay_fine(float);
    subtracts fines and sets status appropriately

  //Print
  void print();
    print details

  //Checks
  bool check_fine();
    true if no fines
    else false
  bool check_limit(string type);
    true if not 5 books or 2 avs
    else false

  //Overloads
  friend ostream & operator << (ostream & , patron);
    print
  friend istream & operator >> (istream & , patron & );
    input details

PATRONS
  //Print
  void print_mailing();
    print name and address of each patron
  void print();
    prints all patron details
  void print_fines();
    prints all patrons with fines

  //Patron Functions
  void add();
    add patron to vector
  void remove();
    remove patron if no fines or checkouts
  void edit();
    finds patron and prompts for new attributes
  void pay_fine();
    finds patron and calls payfine

  //find
  patron & find(int);
    finds patron and returns it
  bool in (int id);
    find patron and returns true or false

  //Save / Load
  void save_patrons(FILE * );
    gets attributes of patrons
    write to file, one row per patron
  void load_patrons(ifstream & );
    reads from file and creates patron

  //Overloads
  friend ostream & operator << (ostream & output, patrons * ps);
    print all patons
  friend istream & operator >> (istream & , patrons * ps);
    creates new patron

LIBITEM
  //print
  virtual void print();
    prints basic details

  virtual void edit();
    prompts the user for new attributes

  //Overload

  friend ostream & operator << (ostream & , libitem * );
    prints
  friend istream & operator >> (istream & , libitem * );
    calls edit

REFERENCE
  basic get/set
  print
  insertion

CD
  basic get/set
  print
  insertion

DVD
  basic get/set
  print
  insertion

BOOK
  basic get/set
  print
  insertion

LIBITEMS
  //Constructors
  ~libitems();
    deallocates all libitems
    empty the vector

  string generate_id();
    tries to find [id]c[number] until it finds a unique copy id

  void print();
    prints all libitem details

  void add(libitem * );
    adds libitem to vector

  void remove();
    removes libitem

  void edit();
    prompts for new attributes of libitem

  libitem * find(string);
    returns libitem with string

  bool in (string id);
    true if item exists, false otherwise

  void admin_edit();
    prompts for new basic attributes

  void load_libitems(ifstream & );
    calls load function for each type of libitem
    void load_books(ifstream & );
    void load_CDs(ifstream & );
    void load_DVDs(ifstream & );
    void load_references(ifstream & );
    writes header with attributes
    writes details of each libitem, one per row

  void save_libitems(FILE * );
    void save_books(FILE * );
    void save_CDs(FILE * );
    void save_DVDs(FILE * );
    void save_references(FILE * );

    reads attributes from a file
    creates a new item and adds to the list of libitems.

  friend ostream & operator << (ostream & output, libitems * ls);
    prints details of all items
  friend istream & operator >> (istream & input, libitems * ls);
    adds a new item

TRANSACTION
  Basic Getters and Setters

  //Overloads
  friend ostream & operator << (ostream & , transaction);
    print
  friend istream & operator >> (istream & , transaction);
    nothing, since you cannot modify a transaction


TRANSACTIONS
  //Constructors
  transactions(patrons * , libitems * );
    idcount = 0
  ~transactions();
    deallocate all patrons
    empty array

  //Transaction Functions
  void lose();
    remove the transaction
    assign fines
    set item status to LOST


  void check_out();
    if patron has no fines
    and patron has no overdue
    and patron does not exceed item limit
    and item is borrowable
      create transaction

  void remove();
    remove transaction
    add fines if book overdue

  void add(transaction);
    only add to vector for loading

  void renew();
    if renewable
      extend due date
      set renewable to false


  //Print
  void print();
    print all transactions

  void print_patrons_with_overdue();
    print all patrons with transactions with due date before today

  void print_patron_checked_out();
    print all transactions with id == patronid

  void print_overdue_items();
    print all transactions with due date before today

  //Find / In
  bool in (int id);
  if found transaction with specified id
    return true
  else return false

  transaction & find(int id);
    if found transaction with specified id
      return it

  //Save / Load
  void load_transactions(ifstream & );
    read number of transactions
    for each transaction
      read transaction data
      create transaction with attributes
      add to controller

  void save_transactions(FILE * );
    write number of transactions
    for each transaction
      write row with attributes

  //Checks
  int check_patron_has_overdue(int);
    for each overdue transaction
      if patron is found, return false
    return true

  //Overloads
  friend ostream & operator << (ostream & output, transactions * ts);
    print all details

  friend istream & operator << (istream & input, transactions * ts);
    add a transaction
```
