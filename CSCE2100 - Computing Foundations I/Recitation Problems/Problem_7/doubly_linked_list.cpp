#include "doubly_linked_list.h"

doubly_linked_list :: doubly_linked_list()
{
   head = NULL; tail = NULL;
}

doubly_linked_list :: doubly_linked_list(string w)
{
    node t = new struct ddnode;
    t->word = w;
    t-> next = NULL;
    t -> prev = NULL;
    head = tail = t;
}

doubly_linked_list :: ~doubly_linked_list()
{
  node t = head;
  node p = NULL;

  while(t){ p = t; t =t->next, p->next = NULL; delete p; }
  head = NULL;
  tail = NULL;
}

void doubly_linked_list :: insert(string w)
{
    node t = new struct ddnode;
    t->word = w;
    t-> next = NULL;
    t -> prev = NULL;

    if(tail)
      { tail -> next = t; t->prev = tail;  tail = tail->next;}
    else
      { tail = head = t;}

}

void doubly_linked_list :: remove (string word) {
  node walk = head;
  while (walk != NULL)
  {
    if (walk->word == word)
    {
      // special case if walk is head or tail
      if (walk == head)
      {
        if (head->next != NULL)
        {
          head->next->prev = NULL;
        }
        head = head->next;
      } else if (walk == tail)
      {
        if (tail->prev != NULL)
        {
          tail->prev->next = NULL;
        }
        tail = tail->prev;
      // else if walk is in the middle
      } else
      {
        if (walk->prev != NULL)
        {
          walk->prev->next = walk->next;
        }
        if (walk->next != NULL)
        {
          walk->next->prev = walk->prev;
        }
      }
    }
    walk = walk->next;
  }
}


void doubly_linked_list :: print_forward()
{
   node t = head;

   while(t) { cout << t->word << " "; t = t->next;}
   cout << endl;

}

void doubly_linked_list :: print_backward()
{
   node t = tail;

   while(t) { cout << t->word << " "; t = t->prev; }
   cout << endl;
}
