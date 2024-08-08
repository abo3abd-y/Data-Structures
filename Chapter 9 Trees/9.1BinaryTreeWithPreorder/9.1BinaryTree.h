#ifndef BINARY_TREE
#define BINARY_TREE

#include "9.1Queue.h"


class binaryTree {

private:
    treeNode *root = nullptr;

public:
    void create();
    void preorder(treeNode *binaryNode);
    // preorder: this is a display function that is supposed to display the whole binary tree
    // it starts from : Node, then go left, then right
    treeNode * return_root ();
};
#endif