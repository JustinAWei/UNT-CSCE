/* Author: Justin Wei
 Date: 11/8/16
 Instructor: David Keathly
 Description: Uses the cctype library to display a message when a digit is entered.
 If a whitespace is entered, display a message indicating such.
*/

//This program reads one character from the keyboard and will
//-convert it to uppercase, if it is lower
//-convert it to lowercase, if it is uppercase
//-display a message, if it is not a letter of the alphabet

#include <iostream>
#include <cctype>
using namespace std;

int main(){
  char c;

  cout << "Enter a character\n";
  c = cin.get();

  if(isalpha(c)){
    if(isupper(c)){
      cout << "Your character " << c << " is in uppercase.";
      c = tolower(c);
      cout << "Its lowercase case is " << c << "." << endl;
    }
    else{
      cout << "your character " << c << " is in lowercase.";
      c = toupper(c);
      cout << "Its uppercase is " << c << "." << endl;
    }
  }

  else if(isdigit(c))
  {
    cout << "The digit you entered was " << c << endl;
  }
  else if(isspace(c)){
    cout << "You entered a blank space" << endl;
  }
  else{
    cout << "Unknown character: " << c<< endl;
  }
  return 0;
}
