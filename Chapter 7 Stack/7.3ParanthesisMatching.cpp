#include <iostream>
#include <string> // you need to include the string class to work on it or with it

using namespace std;

// here we are representing stack as linked lists which might be easier depending on your preferences

struct Node {
    int data;
    Node *next;
};

Node *top = nullptr;

bool isEmpty (Node *topNode) {
    if(!topNode) {return true;}
    return false;
}

bool isFull () {
    Node *newNode = new Node;
    if(!newNode) {
        delete newNode;
        return true;
    }
    delete newNode;
    return false;
}

void push(Node *&topNode, int x) { // we are passing a pointer by reference as you can see
    Node *t = new Node;
    t -> data = x;

    if(!topNode) { // if this the first node that we are adding
       
        t -> next = nullptr;
        topNode = t;
        return;
    }
    t -> next = topNode;
    topNode = t;

}

void pop(Node *&topNode) {
    if(topNode) { // as simple as that as you can see
        Node *t = topNode;
        topNode = topNode -> next;
        delete t;

    }
}

int peek (Node *topNode, int position) {
    // the pointer is not empty and has at least one item in it
    Node *p = topNode;
    for(int i = 1; i < (position) && p;i ++) {
        p = p -> next;
    }

    if(p) {
        return p -> data;
    }
    return -1; // the pointer is either null or the head pointer itself is nullptr

   
}

int stackTop (Node *topNode) {
    if (topNode) {
        return topNode -> data;
    }
    return -1;
}

void display(Node *topNode) {
    Node *p = topNode;

    while(p) {
        cout << p -> data << " ";
        p = p-> next;
    }
    cout  << endl;
}

// in this file, we are solving a problem regarding whether an expression of a string is valid or not; whether the paranthesis are valid so that for every 

// opening paranthesis, there is a closing paranthesis


bool isBalance(string str) { // this function is then supposed to solve this problem as you can see here
    Node *nd;
    nd = nullptr;

    for(std::string::size_type i = 0; i < str.length(); i ++) {
        if(str[i] == '(') {
            push(nd, 1); // just push the value of 1 to the stack assuming that 1 is just representing the opening paranthesis

        }else if(str[i] == ')') {
            if(isEmpty(nd)) {return false;}
            pop(nd);
        }
    }

    return isEmpty(nd); // if it is empty, then return true otherwise return false
}




int main () {

    string st = "((a + b) * (b + d))("; // works with a bunch of cases as you can see here

    // string another_st = ")";

    cout << isBalance(st) << endl; // it is balance as you can see here




    return 0;
}