/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Hamid

Task 1: (5 points)
Modify the print_all_suffix(string) function to count the total number of suffixes and print the number besides printing the suffixes.

Task 2: (10 points)
Write a recursive funtion to generate all possible suffixes.

task 3: (5 points)
How can you count the total number of suffixes without generating them?



*/


#include <iostream>
#include <string>

using namespace std;

void print_all_suffix(string s)
{
  int suffix_count = 0;
  int l = s.length();
  for(int i = l; i >=0 ; i--)
   {
     suffix_count++;
    string ss = s.substr(i,l);
    if(ss.empty())
      cout << "empty string" << endl;
    else
      cout << ss << endl;
   }
   cout << "TOTAL NUMBER OF SUFFIXES: " << suffix_count << endl;
}

void recursive_suffix(string s) {
  if(s.length() == 0) {
    cout << "empty string";
    return;
  }
  cout << s << endl;
  s = s.substr(1, s.length()-1);
  recursive_suffix(s);
}

int main()
{
  string s;

  cout << "Enter a string: ";
  cin >> s;
  cout << s << endl;

  print_all_suffix(s);
  recursive_suffix(s);

  //You can count the total number of suffixes by adding one to the length of the string!
}
