/*
Name: Justin Wei
Course: CSCE2100
Instructor: Hamid
Date 2/12/17
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "word.h"

using namespace std;

class linked_list{
  word *head, *tail;

  public:
    linked_list();
    ~linked_list();
    void grow(string);
    int print();
};

#endif
