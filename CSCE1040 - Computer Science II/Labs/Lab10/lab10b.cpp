/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Description: A program to handle a basic bank system
*/
#include <iostream>
#include <string>
#include "Bank.h"
using namespace std;


int main() {

  //bank object
  Bank bank;

  //for storing bank commands
  string choice;

  //parameters
  int n1, n2, v;


  do {
    //prompt for input and error check
    do {
      cout << "bank> ";
      cin >> choice;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(32767, '\n');
        choice = "";
      }
    } while (choice != "deposit" && choice != "withdraw" && choice != "balance" && choice != "transfer" && choice != "quit");

    //call respective function with correct parammeters
    if (choice == "deposit") {
      //cout << "DEPOSIT SELECTED\n";
      cin >> n1 >> v;
      bank.deposit(n1, v);
    } else if (choice == "balance") {
      //cout << "BALANCE SELECTED\n";
      cin >> n1;
      bank.balance(n1);
    } else if (choice == "transfer") {
      //cout << "TRANSFER SELECTED\n";
      cin >> n1 >> n2 >> v;
      bank.transfer(n1, n2, v);
    } else if (choice == "quit") {
      cout << "QUITTING\n";
      return 0;
    }
  } while (true);

  return 0;
}
