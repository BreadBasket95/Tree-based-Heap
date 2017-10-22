#ifndef TREEHEAP_H
#define TREEHEAP_H

#include "TreeNode.h"
using namespace std;

class TreeHeap{
private:
  TreeNode *root;
  int next_loc;
  void bubble_up(TreeNode *);
  void bubble_down(TreeNode *);
  void clear_heap(TreeNode *);
  TreeNode find_node(int);
public:

  TreeHeap(){
    root = NULL;
    next_loc = 1;
  };
  ~TreeHeap(){
    clear_heap();
  };
  void Insert(string);
  bool Delete(string &);
  void swap(string &, string &);
  void print_heap(TreeNode *);

};
/*
bubble_up(THeapNode*): method that recursively (or iteratively) performs the bubble-up operation
bubble_down(THeapNode*): method that recursively (or iteratively) performs the bubble-down
operation
clear_heap(THeapNode*): uses a post-order traversal to delete all the elements in the tree
find_node(int): receives an integer representing the location of the node to find (assumes root is 1).
This method performs the search procedure to find the node at the passed-in location. It then returns a
pointer to the found node, or NULL if it is not found.
TreeHeap(): constructor, sets root and next_loc to reflect an empty tree (see next_loc above).
~TreeHeap(): destructor that clears the treeheap . May call clear_heap().
Insert(string): creates a new node to store the received argument and then places that node into
the heap at location next_loc. It then calls the bubble-up operation upon that new node. Hint: the
method should use next_loc and find_node() to find the parent node of the new node before adding the
new node. Hint: a non-zero value of next_loc % 2 implies that the last node added to the tree was
the left child of a node.
Delete(string&): uses a reference parameter to return the value of the root and calls bubble-down
on the new root. This method also returns false if the heap is empty, otherwise it returns true. Hint: the
method should use next_loc and find_node() to find the rightmost node in the bottom level.
*/
#endif
