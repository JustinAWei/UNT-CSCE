/*
Name: Justin Wei
Course: CSCE2100
Instructor: Hamid
Date 2/12/17
*/

#include <iostream>
#include <string>
#include <fstream>
#include "linked_list.h"
#include "word.h"
using namespace std;

int main(){

  int n = -1;
  linked_list* list = new linked_list;

  cin >> n;

  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    list->grow(s);
  }

  cout << "The input set contains " << list->print() << " unique words out of total " << n << " words.";
  delete list;
  return 0;
}
