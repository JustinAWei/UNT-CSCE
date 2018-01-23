/* Author: Justin Wei
 Date: 11/8/16
 Instructor: David Keathly
 Description: Uses the cctype library to display a message when a digit is entered.
 If a whitespace is entered, display a message indicating such.
*/

#include <iostream>
using namespace std;

void get_grade(int[]);

int main(){
  int grades[5];

  //update array
  get_grade(grades);

  //print array
  for (int i = 0; i < 5; i++) {
    cout << "grades[" << i << "] = " << grades[i] << endl;
  }

  return 0;
}



/* Function: get_grade
Parameters: an int array to be updated
Return: nothing
Description: This function updates the array given the array
*/
void get_grade(int grade[5]){
  cout << "Enter 5 grades \n";
  for (int i = 0; i < 5; i++) {
    cout << "Input a grade between 0 and 100: ";
    cin >> grade[i];
  }
}
