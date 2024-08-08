#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

struct node {
    node *left;
    int data;
    node *right;
};

// what is a binary search tree: it is a tree that is sorted; the left node's value is smaller than the parent's value. The right node's value is bigger than the parent's value

//there must be no duplicates in the tree in order for this tree to work

// binary search trees work like lists that are sorted in the first place

class binary {
private:
    node *root = nullptr;
public:
    node *binarySearch(node *n, int x);
    node *loopBinarySearch(int x);

    // as you can see from the above functions, we are returning the node if we found it else we return nullptr
    void insert(int x);
    void inorder(node *n); // we always use inorder display functions because they display the tree from smallest to biggest
    node *return_root();
    void deleteNode(int x); // now comes the delete function which will use a loop based algorithm

    //in the delete function as you can see, i used my method instead of using the inorder successor method thing that udemy used
};



#endif