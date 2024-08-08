#ifndef STACK
#define STACK

#include "9.6Queue.h"

using namespace std;

// here we are representing stack as linked lists which might be easier depending on your preferences



class stack{
private:
    Node *top = nullptr;
public:
    bool isEmpty();
    void push(treeNode *x);
    void pop();
    treeNode * stackTop();
    void display();
};



#endif