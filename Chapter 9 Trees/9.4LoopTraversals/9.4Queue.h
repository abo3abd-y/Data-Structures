#ifndef QUEUE
#define QUEUE


// we made some modifications to the queue definition here

struct treeNode { // this is how you define a binary tree as you can see
    treeNode *left;
    int data;
    treeNode *right;
}; // you will see why we defined it here


struct Node {
    treeNode *data; // this should just contain the pointer to the tree node that we want
    Node *next;
};


class queue {

private:
    Node *front = nullptr;
    Node *back = nullptr;
public:
    void enqueue(treeNode *x);
    treeNode * dequeue();
    bool isEmpty();
    void display();
    Node *return_front();
    Node *return_back();

};



#endif
