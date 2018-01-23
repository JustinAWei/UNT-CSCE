/* Author: Justin Wei
 Date: 11/8/16
 Instructor: David Keathly
 Description: stores a series of inputs into an array and then displays them
 in reverse.
*/

#include <iostream>
using namespace std;
int main() {
  int numlist[8], i;

  for (int i = 0; i < 8; i++) {
    cout << "Enter value #" << i+1 << ": ";
    cin >> numlist[i];
  }

  //Display the array backward
  for (int i = 0; i < 8; i++) {
    //since i will be from 0-7, value number will be from 8-0 to 8-7.
    //array indexes are stored from zero hence the 7-i.
    cout << "Value #"<< 8-i << " " << numlist[7-i] << endl;
  }

  return 0;
}
