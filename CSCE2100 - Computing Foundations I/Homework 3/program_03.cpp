/*
Name: Justin Wei
Course: CSCE 2100
Instructor: Hamid
Date: 3/22/2017
*/
#include "binary_search_tree.h"
#include "lfsr.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  int seed, n_taps;
  cin >> seed >> n_taps;
  lfsr lfsr(seed);

  for (int i = 0; i < n_taps; i++) {
    unsigned int input;
    cin >> input;
    lfsr.insert_tap(input);
  }

  lfsr.random_number_generator();
  lfsr.print();

  int* numbers = lfsr.get_numbers();

  //a) initialize the root
  binary_search_tree BST;

  //b) grow the tree (insert new node) when a new number
  for (int i = 0; i < 20; i++) {
    BST.insert(numbers[i]);
  }

  // c) print the tree using in-order traversal
  BST.print_tree();

  // d) print the height of the tree
  BST.print_tree_height();

  // e) print the height of any node
  BST.print_node_height(numbers[3]);

  // f) print the degree of any node
  BST.print_degree(numbers[3]);

  // g) print the leafs of the tree
  BST.print_leaves();

  // h) print the root node of the tree
  BST.print_root();

  // i) delete any node from the tree
  BST.delete_node(numbers[3]);
  BST.print_tree();

  // j) search any node and print the height, degree, and parent
  BST.print_node_details(numbers[4]);
  BST.print_node_details(numbers[5]);
  BST.print_node_details(numbers[6]);

  return 0;
}
