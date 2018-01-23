/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 3110
Instructor: Robert Renka
Date: 9/26/2017


                        CSCE 3110  Program #2


        Due date:  Tuesday, October 3, 2017


        By analogy with the textbook implementation of list (Figures
        3.11 - 3.20), implement a singly linked list with a header
        node, along with a pointer to the header node, but no tail
        node as a class template named singleList.

        Include methods to

          a.  return the size of the linked list,
          b.  print the linked list,
          c.  test if a value x is contained in the linked list,
          d.  insert a value x if it is not already contained in the list,
          e.  remove a value x if it is contained in the linked list.

        You need not include iterators or functions begin and end.

        Include a main function that instantiates a list of integers,
        singleList<int>, and allows an interactive user to execute any
        of the five member functions listed above.

        Your source code should be well-formatted, clean, and readable,
        and the user interface should be well thought out.  This goes
        without saying in every programming assignment.

        Your program should be implemented in a single file named
        prog2_Name.cpp, where Name is your last name, and submitted
        via Blackboard.

*/

#include <iostream>
#include <string>

using namespace std;

template <typename Comparable>
class singleList {

struct node {
  Comparable value;
  node *next = NULL;
};

public:
  singleList() : size(0), head(NULL) {
  }

  ~singleList() {
    cout << "Deleting singleList";
    node* cur = head;
    for(int i = 0; i < size; i++) {
      node* temp = cur;
      cur = cur->next;
      delete temp;
    }
  }

  const int getSize() const {
    return size;
  }

  void print() const {
    node* cur = head;
    for(int i = 0; i < size; i++) {
      cout << cur->value << " -> ";
      cur = cur->next;
    }
    cout << "\\0" << endl;
  }

  bool in(Comparable c) const {
    node* cur = head;
    for(int i = 0; i < size; i++) {
      if (cur->value == c) {
        cout << c << " was found.\n";
        return true;
      }
      cur = cur->next;
    }
    cout << c << " was not found.\n";
    return false;
  }

  void insert(int index, Comparable c) {
    if(index < 0 || index > size) {
      cout << "Index must be between 0 and " << size << endl;
      return;
    }
    if(head == NULL) {
      cout << "inserted " << c << " as head.\n";
      head = new node;
      head -> value = c;
      size++;
      return;
    }
    if(index == 0) {
       if (!in(c)) {
        node* new_node = new node;
        new_node -> value = c;
        new_node -> next = head;
        head = new_node;
        size++;
        return;
      } else {
        cout << "Could not insert value because it already exists.\n";
      }
    }

    else if(!in(c)) {
      node* new_node = new node;
      new_node -> value = c;

      node* cur = head;
      for(int i = 0; i < index - 1; i++) {
        cur = cur->next;
      }

      node* temp = cur->next;

      cur->next = new_node;
      if(temp != NULL) {
        new_node->next = temp;
      }
      size++;
      cout << "inserted " << c << ".\n";
    } else {
      cout << "Could not insert value because it already exists.\n";
    }
    return;
  }

  void remove(Comparable c) {

    //case value is head
    if(head != NULL && head->value == c) {
      cout << "Removed " << c << " at head.\n";

      node* new_head = head->next;
      head->next = NULL;
      delete head;
      head = new_head;
      size--;
      return;
    }

    if (in(c)) {
      node* cur = head;
      for(int i = 0; i < size; i++) {
        if(cur->next != NULL && cur->next->value == c) {
          break;
        }
        cur = cur->next;
      }
      // cur is before the value to be deleted;

      //case avlue is at end
      if(cur->next->next == NULL) {
        node* temp = cur->next;
        cur->next = NULL;
        delete temp;
        size--;
        cout << "Removed " << c << " at end.\n";

        return;
      } else {
        node* temp = cur->next;
        cur->next = cur->next->next;
        temp->next = NULL;
        size--;
        delete temp;
        cout << "Removed " << c << " in the middle.\n";
        return;
      }
    }
    cout << "Could not remove value because it does not exist\n";
    return;
  }

private:
  int size;
  node* head;
};

int main() {
  singleList<int> list;
  // Make booleans print as string
  cout << std::boolalpha;

  string menu = "Which function would you like to use?\na) getSize()\nb) insert(Comparable)\nc) remove(Comparable)\nd) in(Comparable)\ne) print()\n";

  // stores chocie to continue or not
  char cont;

  // stores comparable to insert or remove
  int c, i;

  do {
    // stores choice of function to execute
    char choice = '0';
    do {
      cout << "Here is the list visualized: " << endl;
      list.print();

      cout << menu;
      cin >> choice;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(1000,'\n');
      }
    } while(choice < 'a' || choice > 'e');

    switch(choice) {
      // getSize
      case 'a':
        cout << "List has " << list.getSize() << " element(s)." << endl;
        break;

      // insert
      case 'b':
        cout << "Which index would you like to insert at? " << endl;
        cin >> i;
        if (cin.fail()) {
          cin.clear();
          cin.ignore(1000,'\n');
          break;
        }

        cout << "What is the value of the integer you would like to insert? " << endl;
        cin >> c;
        if (cin.fail()) {
          cin.clear();
          cin.ignore(1000,'\n');
          break;
        }
        list.insert(i, c);
        break;

      // remove
      case 'c':
        cout << "What is the value of the integer you would like to remove? " << endl;
        cin >> c;
        if (cin.fail()) {
          cin.clear();
          cin.ignore(1000,'\n');
          break;
        }
        list.remove(c);
        break;

      // in
      case 'd':
        cout << "What is the value of the integer you would like to find? " << endl;
        cin >> c;
        if (cin.fail()) {
          cin.clear();
          cin.ignore(1000,'\n');
          break;
        }
        list.in(c);
        break;

      // findMin
      case 'e':
        cout << "Here is the list visualized: " << endl;
        list.print();
        break;

      default:
        cout << "Here is the list visualized: " << endl;
        list.print();
        break;

    }

    // prompt to continue or not
    cont = 'y';
    cout << "continue? (Y/n)";
    cin >> cont;
  } while(cont == 'y');


  return 0;
}
