#ifndef BINARY_TREE
#define BINARY_TREE


#include "9.6Queue.h"


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

    // now we do the level order traversal which requires the usage of queues because it prints every level  from left to right
    void levelOrder();
    int nodeCounter(treeNode *binaryNode); // we almost always use postorder traversal when we are doing some sort of analysis such as counting
};
#endif