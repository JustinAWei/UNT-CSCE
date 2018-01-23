/*
Name: Justin Wei
Course: CSCE2100
Instructor: Hamid
Date 2/12/17
*/

#include "word.h"
#include <string>
#include <iostream>

using namespace std;

/*
Name: Word Constructor
Parameters: none
Returns: none
Description: Initializes member variables
*/

word::word(string s) : frequency(1), text(s), next(NULL){}

/*
Name: print
Parameters: none
Returns: none
Description: prints the word and frequency
*/
void word::print(){
  cout << text << ": " << frequency << endl;
}

/*
Name: increase
Parameters: none
Returns: none
Description: increases freq by 1
*/
void word::increase(){
  frequency++;
};
