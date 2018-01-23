/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Description: A program to handle basic I/O of bank commands
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
  string choice;

  do {
    //prompt for command input and error check
    do {
      cout << "bank> ";
      cin >> choice;
      if(cin.fail()) {
        cin.clear();
        cin.ignore(32767, '\n');
        choice = "";
      }
    } while (choice != "deposit" && choice != "withdraw" && choice != "balance" && choice != "transfer" && choice != "quit");

    //print respective command
    if (choice == "deposit") {
      cout << "DEPOSIT SELECTED\n";
    } else if (choice == "balance") {
      cout << "BALANCE SELECTED\n";
    } else if (choice == "transfer") {
      cout << "TRANSFER SELECTED\n";
    }

    //quit if selected
    else if (choice == "quit") {
      cout << "QUITTING\n";
      return 0;
    }
  } while (true);

  return 0;
}
