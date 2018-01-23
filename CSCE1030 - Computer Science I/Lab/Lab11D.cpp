/* Author: Justin Wei
 Date: 11/15/16
 Instructor: David Keathly
 Description: Converts a string to a cstring to use when opening a file.
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
  int x, count = 0;
  float sum = 0, avg;
  string input_file;
  ifstream in_s;

  cout << "Please enter the input file name: ";
  cin >> input_file;
  in_s.open(input_file.c_str());

  if(in_s.fail()){
    cout << "ERROR: Unable open Input file.\n";
    exit(EXIT_FAILURE);
  }
  cout << "\t x \t\t x^2 \t\t Current Sum \n";
  cout << "\t === \t\t === \t\t  ========= \n";
  while(in_s >> x){
    sum += x;
    cout << "\t " << x << "\t\t  " << pow(x, 2) << "\t\t  " << sum << "\n";
    count++;
  }

  avg = sum/count;
  cout << "\n \t The average of these " << count << " numbers is: " << avg << endl;

  in_s.close();
  return 0;
  }
