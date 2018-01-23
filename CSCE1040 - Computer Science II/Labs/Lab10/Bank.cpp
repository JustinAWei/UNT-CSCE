/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Keathly
Description: A class definition of a simple bank system
*/

#include "Bank.h"
#include <string>
#include <iostream>

using namespace std;

Bank::Bank() {
  //set all accounts to 0
  for(int i = 0; i < 10; i++) {
    accounts[i]= 0;
  }
}

void Bank::deposit(int num, int value) {
  //add value to account
  accounts[num] += value;
}

bool Bank::withdraw(int num, int value) {
  //check if enough money
  if (value > accounts[num]) {
    cout << "Error! Funds exceeded.\n";
    return false;
  }
  accounts[num] -= value;
  return true;
}

void Bank::balance(int num) {
  //print balance in account
  cout << "Balance in account " << num << " : " << accounts[num] << endl;
}

void Bank::transfer(int num1, int num2, int value) {
  //if able to withdraw, transfer
  if(withdraw(num1, value)) {
    deposit(num2, value);
  }
}
