/*
Name: Justin Wei
Course: CSCE 1040
Instructor: Keathly
*/

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
  string s;

  //get all the input
  while(cin >> s) {

    //for breaking outer loop
    bool cont = false;


    // "base" cases
    if(s[0] != 'A') {
      cout << "INVALID " << s << endl;
      continue;
    }

    if(s.length() == 1) {
      cout << "VALID " << s << endl;
      continue;
    }

    //keep track of previous letter
    string prev = "";
    prev += s[0];

    for(int i = 1; i < s.length(); i++) {

      //A must be followed by a or b
      if(prev == "A" && (s[i] != 'A' && s[i] != 'B')) {
        cout << "INVALID " << s << endl;
        cont = true;
        break;
      }

      //b must be followed by a b
      else if (prev == "B" && s[i] != 'B') {
        cout << "INVALID " << s << endl;
        cont = true;
        break;
      }

      //bb must be followed by an a
      else if (prev == "BB" && s[i] != 'A') {
        cout << "INVALID " << s << endl;
        cont = true;
        break;
      }

      //if prev is a, set the next to prev
      if (prev == "A") {
        prev = s[i];
        continue;
      }

      //if prev is b, next has to be bb
      else if (prev == "B") {
        prev = prev + s[i];
        continue;
      }

      //if prev is bb, next has to be an a
      else if (prev == "BB") {
        prev = s[i];
        continue;
      }
    }

    //the string failed a check, its invalid
    if (cont) {
      continue;
    }

    //all of the string is valid, print valid
    cout << "VALID " << s << endl;
  }

  return 0;
}
