/*
Name: Justin Wei
Course: CSCE2100
Instructor: Hamid
Date 2/12/17
*/

#include "word.h"
#include "linked_list.h"
#include <string>
#include <iostream>

using namespace std;

//constructor initializes head and tail of linked list
linked_list::linked_list() : head(NULL), tail(NULL) {};

linked_list::~linked_list(){
  word* cur = head;
  while(cur != NULL){
    word* temp = cur;
    cur = cur->next;
    delete temp;
  }
}

//adds a word to the linked list
void linked_list::grow(string w){
  if (head == NULL){
    head = new word(w);
    tail = head;
  }
  else{
    word* cur = head;

    //if word exists, add one to freq
    while(cur != NULL){
      if(cur->text == w){
        cur->increase();
        return;
      }
      cur = cur->next;
    }

    //else add word to linked list
    tail->next = new word(w);
    tail = tail->next;
  }
}

//prints everything and returns amount of unique words
int linked_list::print(){
  int unique = 0;
  word* cur = head;
  //print each word and keep a count
  while(cur != NULL){
    unique++;
    cur->print();
    cur = cur->next;
  }
  return unique;
}
