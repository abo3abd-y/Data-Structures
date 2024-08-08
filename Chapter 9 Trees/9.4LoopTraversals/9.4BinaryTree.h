#ifndef BINARY_TREE
#define BINARY_TREE


#include "9.4Queue.h"


class binaryTree {

private:
    treeNode *root = nullptr;

public:
    void create();
    // preorder: this is a display function that is supposed to display the whole binary tree
    // it starts from : Node, then go left, then right
    treeNode * return_root ();
    void preorder(treeNode *binaryNode);
    void inorder (treeNode *binaryNode); // this means that we go left first, print, then we go right
    void postorder (treeNode *binaryNode); //this means that we go left, then right, then we finally print


    // the following is the loop version of the above recursive display functions that we talked about
    void loopPreorder ();
    void loopInorder();
    void loopPostorder();
    

};
#endif