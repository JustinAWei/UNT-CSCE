/*
Justin Wei
CSCE2100
Hamid
2/3/17

1. Write a program that will use recursion and print an input string in reverse.
Sample input and output:
Input: computer
Output: retupmoc
*/
#include <string>
#include <iostream>

using namespace std;

void print_backward(string &s, int pos){
  pos--;
  if(pos < 0){
    return;
  }
  cout << s[pos];
  print_backward(s, pos);
}

int main(){
  string in;
  cout << "Enter the string to print backwards: ";
  cin >> in;
  cout << "Here is the string backward: ";
  print_backward(in, in.length());
  return 0;
}
