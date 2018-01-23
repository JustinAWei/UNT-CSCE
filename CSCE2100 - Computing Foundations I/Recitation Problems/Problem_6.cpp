/*
Name: Justin Wei
Instructor: Hamid

Topic: Likned List
Points:(20)
Write a program where you-

1-> Create a class to implement "Double Linked List" of integers-> (10)
2-> Create the list and print the list in forward and reverse directions-> (10)

*/



#include <iostream>
#include <string>

using namespace std;

struct node {
  int value;
  node *prev, *next;
};

class DoubleLinkedList{
  int length;
  node *head, *tail;
  public:

    DoubleLinkedList() : length(0), head(NULL), tail(NULL) {}

    void add(int n) {
      node* new_node = new node;
      new_node->value = n;
      if(head == NULL) {
        head = new_node;
        tail = new_node;
      }
      else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = tail->next;
      }
    }
    void print(){
      node *cur = head;
      while (cur != NULL) {
        cout << cur->value << " ";
        cur = cur->next;
      }
    }
};

int main(){
  DoubleLinkedList list;

  for(int i = 0; i < 10; i++) {
    list.add(i);
  }

  list.print();
  return 0;
}
