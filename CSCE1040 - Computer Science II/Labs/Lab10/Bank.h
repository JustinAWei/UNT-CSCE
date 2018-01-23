/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Description: A class declaration for a simple bank system
*/

#ifndef BANK_H
#define BANK_H

class Bank{

  //A bank has 10 accounts indexed 0 - 9
  int accounts[10];

  public:

    /*
    Function Name: Bank Constructor
    Parameters: None
    Returns: None
    Description: Initializes the accounts to 0
    */
    Bank();


    /*
    Function Name: Deposit
    Parameters: two ints for the account number and value to deposit
    Returns: None
    Description: deposits a value into an account
    */
    void deposit(int num, int value);


    /*
    Function Name: withdraw
    Parameters: two ints for the account number and value to withdraw
    Returns: A boolean stating wheter there is enough money to withdraw
    Description: Withdraws the specified amount from an account if possible
    */
    bool withdraw(int num, int value);


    /*
    Function Name: balance
    Parameters: a account number
    Returns: None
    Description: prints the value in a specified account
    */
    void balance(int num);


    /*
    Function Name: transfer
    Parameters: three ints for source and destination accounts and a value
    Returns: None
    Description: Transfers money from one account to the other if possible
    */
    void transfer(int num1, int num2, int value);
};

#endif
