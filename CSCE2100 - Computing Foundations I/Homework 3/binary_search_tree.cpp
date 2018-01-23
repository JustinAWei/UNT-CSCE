/*
Name: Justin Wei
Course: CSCE 2100
Instructor: Hamid
Date: 3/22/2017
*/

#include "binary_search_tree.h"
#include <iostream>

using namespace std;

binary_search_tree::binary_search_tree() {
  root = NULL;
}

binary_search_tree::binary_search_tree(int root_value) {
  root = new tree_node;
  root->value = root_value;
}

void binary_search_tree::print_node_details(int x) {
  cout << "\nSearching for Node " << x << "..." << endl;
  cout << "================\n";

  if (search(x)) {
    tree_node * t = get_node(x);
    cout << "Node " << x << " details:\n";
    cout << "Parent: ";

    if (parent(x, root) != NULL) {
      if (parent(x, root)->value == x) {
        cout << "root\n";
      } else {
        cout << parent(x, root)->value << endl;
      }
    } else {
      cout << "none" << endl;
    }
    print_degree(x);
    print_node_height(x);

  } else {
    cout << "Node " << x << " not found.\n";
  }
  cout << "================\n\n";
}

void binary_search_tree::insert(int new_value) {
  if (root == NULL) {
    root = new tree_node;
    root->value = new_value;
  } else {
    tree_node * walk = root;
    while (walk != NULL) {
      if (new_value < walk->value) {
        if (walk->left_node == NULL) {
          walk->left_node = new tree_node;
          walk->left_node->value = new_value;
          return;
        } else {
          walk = walk->left_node;
        }
      } else if (new_value > walk->value) {
        if (walk->right_node == NULL) {
          walk->right_node = new tree_node;
          walk->right_node->value = new_value;
          return;
        } else {
          walk = walk->right_node;
        }
      } else {
        return;
      }
    }
  }
}

void binary_search_tree::print_tree() {
  cout << "printing tree:\n";
  recurse_print_tree(root);
  cout << endl;
}

void binary_search_tree::recurse_print_tree(tree_node * t) {
  if (t == NULL) {
    return;
  } else {
    recurse_print_tree(t->left_node);
    cout << t->value << " ";
    recurse_print_tree(t->right_node);
  }
}

void binary_search_tree::print_tree_height() {
  cout << "tree height: " << recurse_height(root) << endl;
}

struct tree_node * binary_search_tree::get_node(int key) {
  if (root == NULL) {
    return NULL;
  } else {
    tree_node * walk = root;
    while (walk != NULL) {
      if (key < walk->value) {
        walk = walk->left_node;
      } else if (key > walk->value) {
        walk = walk->right_node;
      } else {
        return walk;
      }
    }
    return NULL;
  }
}

int binary_search_tree::recurse_height(tree_node * t) {
  if (t == NULL) {
    return 0;
  } else {
    return 1 + max(recurse_height(t->left_node), recurse_height(t->right_node));
  }
}

void binary_search_tree::print_node_height(int key) {
  cout << "node " << key << " height: " << recurse_height(get_node(key)) << endl;
}

void binary_search_tree::print_degree(int key) {
  if (root == NULL || !search(key)) {
    cout << "degree of " << key << " is " << 0 << endl;
  } else {
    tree_node * node = get_node(key);
    cout << "degree of " << key << " is " << !(key == root->value) + (node->left_node != NULL) + (node->right_node != NULL) << endl;
  }
}

void binary_search_tree::print_leaves() {
  cout << "leaves: ";
  recurse_leaves(root);
  cout << endl;
}

void binary_search_tree::recurse_leaves(tree_node * t) {
  if (t == NULL) {
    return;
  }
  if (t->right_node == NULL && t->left_node == NULL) {
    cout << t->value << " ";
    return;
  }
  if (t->right_node != NULL) {
    recurse_leaves(t->right_node);
  }

  if (t->left_node != NULL) {
    recurse_leaves(t->left_node);
  }
}

void binary_search_tree::print_root() {
  if (root == NULL) {
    cout << "no root\n";
  } else {
    cout << "root: " << root->value << endl;
  }
}

bool binary_search_tree::search(int key) {
  if (root == NULL) {
    return NULL;
  } else {
    tree_node * walk = root;
    while (walk != NULL) {
      if (key < walk->value) {
        walk = walk->left_node;
      } else if (key > walk->value) {
        walk = walk->right_node;
      } else {
        return true;
      }
    }
    return false;
  }
}

tree_node * binary_search_tree::min_node(tree_node * t) {
  while (t->left_node != NULL) {
    t = t->left_node;
  }
  return t;
}

void binary_search_tree::delete_node(int x) {
  if (search(x)) {
    tree_node * t = get_node(x);
    tree_node * p = parent(x, root);
    if (p->value == x) {
      cout << "deleting root.\n";
      if (root->left_node == NULL && root->right_node == NULL) {
        delete root;
        root = NULL;
      } else if (root->left_node == NULL) {
        root = root->right_node;
      } else if (root->right_node == NULL) {
        root = root->left_node;
      } else {
        int min = min_node(t->right_node)->value;
        delete_node(min);
        root->value = min;
      }
    } else {
      cout << "deleting " << x << ".\n";
      if (t->left_node == NULL && t->right_node == NULL) {
        if (p->left_node != NULL && p->left_node == t) {
          delete p->left_node;
          p->left_node = NULL;
        } else {
          delete p->right_node;
          p->right_node = NULL;
        }
      } else if (t->left_node == NULL) {
        if (p->left_node != NULL && p->left_node->value == x) {
          p->left_node = t->right_node;
          delete t;
        } else {
          p->right_node = t->right_node;
          delete t;
        }
      } else if (t->right_node == NULL) {
        if (p->left_node != NULL && p->left_node->value == x) {
          p->left_node = t->left_node;
          delete t;
        } else {
          p->right_node = t->left_node;
          delete t;
        }
      } else {
        int min = min_node(t->right_node)->value;
        delete_node(min);
        t->value = min;
      }
    }
  }
}

void binary_search_tree::recurse_delete(int x) {}

struct tree_node * binary_search_tree::parent(int key, tree_node * n) {
  if (n == NULL) {
    return NULL;
  } else if (key == n->value) {
    return n;
  } else if ((n->right_node != NULL && n->right_node->value == key) || (n->left_node != NULL && n->left_node->value == key)) {
    return n;
  } else if (key < n->value) {
    return parent(key, n->left_node);
  } else if (key > n->value) {
    return parent(key, n->right_node);
  }
}
