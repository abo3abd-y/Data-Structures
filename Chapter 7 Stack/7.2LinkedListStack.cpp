#include <iostream>

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


int main () {

    push(top, 10);
    push(top, 20);
    push(top, 30);
    push(top, 40);
    push(top, 50);

    display(top);

    cout << stackTop(top) << endl;

    cout << peek(top, 1) << " " << peek(top, 2) << " " << peek(top, 3) << " " << peek(top, 4) << " " << peek(top, 5) << endl; // works perfectly as you can see here

    pop(top); // works perfectly as you can see
    pop(top);

    display(top);

    cout << isEmpty(top) << endl; // works perfectly as you can see here which is a good thing



    return 0;
}