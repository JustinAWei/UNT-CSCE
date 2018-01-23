/*
Name: Justin Wei
Course: CSCE 2100
Instructor: Hamid
Date: 3/22/2017
*/
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <string>

using namespace std;

struct tree_node {
  int value;
  struct tree_node *left_node;
  struct tree_node *right_node;
};

class binary_search_tree {
  tree_node *root;

  private:
    void recurse_print_tree(tree_node*);
    int recurse_height(tree_node*);
    void recurse_leaves(tree_node*);
    void recurse_delete(int);
    struct tree_node*get_node(int node_key);
    struct tree_node*min_node(tree_node*);
    struct tree_node*parent(int key, tree_node*);

  public:

    //Constructors
    binary_search_tree();
    binary_search_tree(int);

    //grow the tree
    void insert(int);

    //print the whole tree by traversing inorder
    void print_tree();

    //print the tree height
    void print_tree_height();

    //prints the height of a single node
    void print_node_height(int);

    //prints the degree of a single node
    void print_degree(int);

    //prints all of the leaves
    void print_leaves();

    //prints the value of the root
    void print_root();

    //deletes a node
    void delete_node(int);

    //true if node is found, false otherwise
    bool search(int);

    //prints the node value, degree, height, and parent
    void print_node_details(int);
};
#endif
