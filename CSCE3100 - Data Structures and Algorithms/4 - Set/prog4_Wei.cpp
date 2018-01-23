/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 3110
Instructor: Robert Renka
*/

#include <stack>
#include <iostream>
#include <string>

using namespace std;

template <typename Comparable>
  class Set {
    public:
      Set(): root(NULL), size(0) {}
    Set(const Set & rhs);

    struct BinaryNode {
      Comparable element;
      BinaryNode* parent;
      BinaryNode* left;
      BinaryNode* right;

      BinaryNode(const Comparable & theElement, BinaryNode* lt, BinaryNode* rt): element(theElement), left(lt), right(rt), parent(NULL) {}
    };

    class const_iterator {
      public:
        BinaryNode* current;
      stack <BinaryNode*> recursiveStack;
      const_iterator(): current(NULL) {}

      const Comparable & operator* () const {
        return retrieve();
      }

      const_iterator & operator++() {
        if (current->right != NULL) {
          recursiveStack.push(current->right);
          if (current->right->left != NULL) {
            recursiveStack.push(current->right->left);
          }
        }
        if (recursiveStack.size() == 0) {
          current = NULL;
          return *this;
        }

        current = recursiveStack.top();
        recursiveStack.pop();
        return *this;
      }

      const_iterator operator++(int) {
        const_iterator old =* this;
        ++(* this);
        return old;
      }

      bool operator == (const const_iterator & rhs) const {
        return current == rhs.current;
      }
      bool operator != (const const_iterator & rhs) const {
        return !(* this == rhs);
      }

      protected:
        Comparable & retrieve() const {
          return current->element;
        }

      const_iterator(BinaryNode* p) {
        BinaryNode* root = p;
        while (root != NULL) {
          recursiveStack.push(root);
          root = root->left;
        }
        if (recursiveStack.size()> 0) {
          current = recursiveStack.top();
          recursiveStack.pop();
        } else {
          current = NULL;
        }
      }

      friend class Set <Comparable>;
    };

    class iterator: public const_iterator {
      public: iterator() {}

      Comparable & operator* () {
        return this->retrieve();
      }
      const Comparable & operator* () const {
        return const_iterator::operator* ();
      }


      iterator & operator++() {
        if (this->current->right != NULL) {
          this->recursiveStack.push(this->current->right);
          if (this->current->right->left != NULL) {
            this->recursiveStack.push(this->current->right->left);
          }
        }
        if (this->recursiveStack.size() == 0) {
          this->current = NULL;
          return *this;
        }

        this->current = this->recursiveStack.top();
        this->recursiveStack.pop();
        return *this;
      }

      iterator operator++(int) {
        iterator old =* this;
        ++(* this);
        return old;
      }

      protected: iterator(BinaryNode* p): const_iterator(p) {}

      friend class Set <Comparable>;
    };

    const Comparable & findMin() const;
    const Comparable & findMax() const;
    bool isEmpty() const;
    void printTree() const {
      printTree(root);
    }

    /**
    * Returns true if x is found in the tree.
    */
    bool contains(const Comparable & x) const {
      return contains(x, root);
    }

    /**
    * Insert x into the tree; duplicates are ignored.
    */
    void insert(const Comparable & x) {
      insert(x, root, NULL);
    }

    /**
    * Remove x from the tree. Nothing is done if x is not found.
    */
    void remove(const Comparable & x) {
      remove(x, root);
    }
    /*
    * Returns size of tree
    */
    int getsize() {
      return size;
    }
    iterator begin() {
      return iterator(root);
    }
    iterator end() {
        iterator my_iterator = iterator(root);
        for (int i = 0; i <size; i++) {
          my_iterator++;
        }
        return my_iterator;
      }
      /**
      * Destructor for the tree
      */
      ~Set() {
        makeEmpty(root);
      }
    /**
    * Deep copy.
    */
    const Set & operator = (const Set & rhs) {
      if (this != & rhs) {
        makeEmpty();
        root = clone(rhs.root);
      }
      return *this;
    }


    private:
      int size;
    BinaryNode* root;


    /**
    * Internal method to clone subtree.
    */
    BinaryNode* clone(BinaryNode* t) const {
      if (t == NULL)
        return NULL;

      return new BinaryNode(t->element, clone(t->left), clone(t->right));
    }

    /**
    * Internal method to test if an item is in a subtree.
    * x is item to search for.
    * t is the BinaryNode that roots the subtree.
    */
    bool contains(const Comparable & x, BinaryNode* t) const {
      if (t == NULL)
        return false;
      else if (x <t->element)
        return contains(x, t->left);
      else if (t->element <x)
        return contains(x, t->right);
      else
        return true; // Match
    }


    /**
    * Internal method to make subtree empty.
    */
    void makeEmpty(BinaryNode* & t) {
      if (t != NULL) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
      }
      t = NULL;
    }

    /**
    * Internal method to find the smallest item in a subtree t.
    * Return BinaryNode containing the smallest item.
    */
    BinaryNode* findMin(BinaryNode* t) const {
      if (t == NULL)
        return NULL;
      if (t->left == NULL)
        return t;
      return findMin(t->left);
    }

    /**
    * Internal method to find the largest item in a subtree t.
    * Return BinaryNode containing the largest item.
    */
    BinaryNode* findMax(BinaryNode* t) const {
      if (t != NULL)
        while (t->right != NULL)
          t = t->right;
      return t;
    }

    /**
    * Internal method to insert into a subtree.
    * x is the item to insert.
    * t is the BinaryNode that roots the subtree.
    * Set the new root of the subtree.
    */
    void insert(const Comparable & x, BinaryNode* & t, BinaryNode* parent) {
      if (t == NULL) {
        t = new BinaryNode(x, NULL, NULL);
        t->parent = parent;
        size++;
      } else if (x <t->element) {
        insert(x, t->left, t);
      } else if (t->element <x) {
        insert(x, t->right, t);
      } else
     ; // Duplicate; do nothing

    }

    /**
    * Internal method to remove from a subtree.
    * x is the item to remove.
    * t is the BinaryNode that roots the subtree.
    * Set the new root of the subtree.
    */
    void remove(const Comparable & x, BinaryNode* & t) {
      if (t == NULL)
        return; // Item not found; do nothing
      if (x < t->element)
        remove(x, t->left);
      else if (t->element <x)
        remove(x, t->right);
      else if (t->left != NULL && t->right != NULL) // Two children
      {
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
      } else {
        BinaryNode* prevNode = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete prevNode;
        size--;
      }
    }

    void printTree(BinaryNode * t) const {
      if (t == NULL) {
        return;
      }
      if(t->left != NULL) {
        printTree(t->left);
      }
      cout << t->element << " ";
      if(t->right != NULL) {
        printTree(t->right);
      }
      return;
    }
  };

int main() {
  Set<int> set;
  string menu = "Which function would you like to use?\na) insert()\nb) remove()\nc) in()\nd) print()\n";

  // stores chocie to continue or not
  char cont;

  // stores comparable to insert or remove
  int c, i;

  do {
    // stores choice of function to execute
    char choice = '0';
    do {
      cout << menu;
      cin >> choice;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(1000,'\n');
      }
    } while(choice < 'a' || choice > 'd');

    switch(choice) {
      case 'a':
        cout << "What is the value of the integer you would like to insert? " << endl;
        cin >> c;
        if (cin.fail()) {
          cin.clear();
          cin.ignore(1000,'\n');
          break;
        }
        set.insert(c);
        break;

      case 'b':
        cout << "What is the value of the integer you would like to remove?";
        cin >> c;
        if (cin.fail()) {
          cin.clear();
          cin.ignore(1000,'\n');
          break;
        }
        set.remove(c);

        break;

      case 'c':
        cout << "What is the value of the integer you would like to check? " << endl;
        cin >> c;
        if (cin.fail()) {
          cin.clear();
          cin.ignore(1000,'\n');
          break;
        }
        if(set.contains(c)) {
          cout << "the set contains " << c << endl;
        } else {
          cout << "the set does not contain " << c << endl;
        }
        break;

      case 'd':
        set.printTree();
        break;

    }

    // prompt to continue or not
    cont = 'y';
    cout << "continue? (Y/n)";
    cin >> cont;
  } while(cont == 'y');



  return 0;
}
