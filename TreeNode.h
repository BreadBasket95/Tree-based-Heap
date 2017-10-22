// Marc Moore 10-17
// TreeNode.h
// This is the header file for the TreeNode class
// which is used to populate the heap

#ifndef TREENODE_H
#define TREENODE_H

#include <string>
using namespace std;

struct TreeNode {
  string data;
  int location;
  TreeNode *parent;
  TreeNode *left;
  TreeNode *right;
  TreeNode(string d){
      data = d;
      parent = NULL;
      left = NULL;
      right = NULL;
    };
};

/*
//Member descriptions:
//data: the data to be stored by the node
//parent: a pointer to the parent of the node
left: a pointer to the left child node
right: a pointer to the right child node
Method descriptions:
THeapNode(string): constructor that receives the data to be stored by the node and sets the
THeapNode pointers to NULL
*/
#endif
