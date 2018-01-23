#ifndef doubly_linked_list_H
#define doubly_linked_list_H

#include <iostream>
#include <string>
using namespace std;


typedef struct ddnode* node;

struct ddnode
{
  string word;
  struct ddnode *next;
  struct ddnode *prev;
};

class doubly_linked_list
{
   node head;
   node tail;


   public:
      doubly_linked_list();
      doubly_linked_list(string);
      void insert(string);
      void remove(string);
      void print_forward();
      void print_backward();
      ~doubly_linked_list();

};

#endif
