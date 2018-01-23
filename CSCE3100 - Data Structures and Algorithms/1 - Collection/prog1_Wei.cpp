/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 3110
Instructor: Robert Renka
Date: 9/12/2017


                        CSCE 3110  Program #1


        Due date:  Tuesday, September 19, 2017


        Design a class template, OrderedCollection, that stores a
        collection of Comparables in an array, along with the current
        size of the collection.  The term 'ordered collection' here
        means a totally ordered set; the elements need not be stored
        in any particular order.

        Use dynamic memory allocation to create a C-style array, and
        provide an array capacity that is generally larger than the
        array size.  Insertion into a full array must result in
        the array being reallocated with a larger capacity.  Refer
        to the text implementation of class Vector in Figures 3.7
        and 3.8.

        Provide public functions isEmpty, makeEmpty, insert, remove,
        findMin, and findMax.  Function remove should take a Comparable
        as argument and search the array for its presence.  It should
        also return a boolean with value true iff the Comparable was
        found and removed.

        Include a main function that instantiates a collection of
        integers, OrderedCollection<int>, and (in a loop) allows an
        interactive user to execute any of the six member functions
        listed above (or to terminate the program).

        Your program should be implemented in a single file named
        prog1_Name.cpp, where Name is your last name, tested using
        gnu gcc, and submitted via Blackboard.

*/

#include <iostream>
#include <string>

using namespace std;

template <typename Comparable>
class OrderedCollection {
private:
  int curr_size, capacity;
  Comparable* arr;

  /*
  Name: Resize
  Parameters: Integer for the new capacity
  Description: Replaces array with another dynamically allocated array of Comparables with 2N + 1 capacity.
  */
  void resize(int new_capacity) {
    // temporarily store current array
    Comparable* old_arr = arr;

    // create new array with new capacity
    arr = new Comparable[new_capacity];
    capacity = new_capacity;

    // copy values from old to new array
    for (int i = 0; i < curr_size; i++) {
      arr[i] = old_arr[i];
    }

    // delete old array
    delete[] old_arr;
  }


public:
  /*
  Name: Print
  Parameters: None
  Description: Prints the size, capacity, and contents of the current array
  */
  void print() {
    cout << "size: " << curr_size;
    cout << "\t capacity: " << capacity << endl;
    for (int i = 0; i < capacity; i++) {
      cout << arr[i] << " ";
    }
    cout << endl << endl;
  }

  /*
  Name: OrderedCollection
  Parameters: An integer for the capacity, defaulted at 10
  Description: Dynamically initializes the current array
  */
  OrderedCollection(int capacity = 10) : curr_size(0), capacity(capacity) {
    arr = new Comparable[capacity];
  }

  /*
  Name: ~OrderedCollection
  Parameters: None
  Description: Cleans up the current array by unallocating it.
  */
  ~OrderedCollection() {
    delete[] arr;
  }

  /*
  Name: isEmpty
  Parameters: None
  Description: Returns a bool to represents whether the current array is emppty or not
  */
  bool isEmpty() const {
    return curr_size == 0;
  }

  /*
  Name: makeEmpty
  Parameters: None
  Description: Resets the array to initial form.
  */
  void makeEmpty() {
    // temporarily stores the current array
    Comparable* old_arr = arr;

    // names a new empty array with the same capacity
    arr = new Comparable[capacity];

    // resets the current size to zero
    curr_size = 0;

    // delete old array
    delete[] old_arr;

  }

  /*
  Name: Insert
  Parameters: Comparable to  specify the value to insert
  Description: Inserts into the array a comparable, resizing if needed.
  */
  void insert(Comparable c) {
    if(curr_size == capacity) {
      resize(2 * capacity + 1);
    }

    arr[curr_size++] = c;
  }

  /*
  Name: Remove
  Parameters: A comparable to specify the value to remove
  Description: Finds the first value that matches the comparable value specified and removes it.
  */
  bool remove(Comparable c) {
    // store the index to remove in remove_i
    int remove_i = -1;
    for (int i = 0; i < curr_size; i++) {
      if(arr[i] == c) {
        remove_i = i;
        break;
      }
    }

    // if value is in  array and can be removed
    if(remove_i != -1) {

      // temporarily stores current array
      Comparable* old_arr = arr;

      // creates a new array with same capacity
      arr = new Comparable[capacity];

      // k stores the current index of the new array
      int k = 0;

      // copies every value except for the index specified to be removed
      for (int i = 0; i < curr_size; i++) {
        if(i != remove_i) {
          arr[k++] = old_arr[i];
        }
      }

      // decreases size by one
      curr_size--;

      return true;
    } else {
      return false;
    }
  }

  /*
  Name: findMin
  Parameters: None
  Description: Finds the minimum value in the current array
  */
  Comparable findMin() const {
    int min_i = 0;
    for (int i = 0; i < curr_size; i++) {
      if(arr[min_i] > arr[i]) {
        min_i = i;
      }
    }
    return arr[min_i];
  }

  /*
  Name: findMin
  Parameters: None
  Description: Finds the maximum value in the current array
  */
  Comparable findMax() const {
    int max_i = 0;
    for (int i = 0; i < curr_size; i++) {
      if(arr[max_i] < arr[i]) {
        max_i = i;
      }
    }
    return arr[max_i];
  }
};

int main() {
  // Make booleans print as string
  cout << std::boolalpha;


  // initialize OrderedCollection of Integers
  OrderedCollection<int> int_collection;

  string menu = "Which function would you like to use?\na) isEmpty()\nb) makeEmpty()\nc) insert(Comparable)\nd) remove(Comparable)\ne) findMin()\nf) findMax()\n";

  // stores chocie to continue or not
  char cont;

  // stores comparable to insert or remove
  int c;

  do {
    // stores choice of function to execute
    char choice = '0';
    do {
      cout << "Here is the array visualized: " << endl;
      int_collection.print();

      cout << menu;
      cin >> choice;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(1000,'\n');
      }
    } while(choice < 'a' || choice > 'f');

    switch(choice) {
      // isEmpty
      case 'a':
        cout << (int_collection.isEmpty() ? "Array is empty" : "Array is not empty.") << endl;
        break;

      // makeEmpty
      case 'b':
        cout << "Making empty.\n";
        int_collection.makeEmpty();
        break;

      // insert
      case 'c':
        cout << "What is the value of the integer you would like to insert? " << endl;
        cin >> c;
        if (cin.fail()) {
          cin.clear();
          cin.ignore(1000,'\n');
          break;
        }
        int_collection.insert(c);
        break;

      // remove
      case 'd':
        cout << "What is the value of the integer you would like to remove? " << endl;
        cin >> c;
        if (cin.fail()) {
          cin.clear();
          cin.ignore(1000,'\n');
          break;
        }
        int_collection.remove(c);
        break;

      // findMin
      case 'e':
        cout << "Min: " << int_collection.findMin() << endl;
        break;

      // findMax
      case 'f':
        cout << "Max: " << int_collection.findMax() << endl;
        break;

      default:
        break;
    }

    // prompt to continue or not
    cont = 'y';
    cout << "continue? (Y/n)";
    cin >> cont;
  } while(cont == 'y');

  return 0;
}
