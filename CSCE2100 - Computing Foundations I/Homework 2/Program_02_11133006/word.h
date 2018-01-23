/*
Name: Justin Wei
Course: CSCE2100
Instructor: Hamid
Date 2/12/17
*/

#ifndef WORD_H
#define WORD_H
#include <string>
using namespace std;

class word{
  string text;
  int frequency;
  word* next;

  friend class linked_list;

  public:
    word(string);
    void print();
    void increase();
};

#endif
