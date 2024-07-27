#include <iostream>

using namespace std;

struct Node { // this is how you can create a linked list in c++
    int data;
    Node *next;
}*first; 

void create (int a[], int n) { // we initialize a linked list using an array 
    int i;

    Node *t;

    first = new Node;
    first -> data = a[0];
    first -> next = NULL;
    t = first;
    
    
    for(i =1; i < n;i ++) {
        t -> next = new Node;
        t = t-> next;
        t -> data = a[i];
        t -> next = NULL;
    }

}

void display (Node *p) { // we display the linked list using a linked list
    while (p != NULL) {
        cout << p -> data << endl;
        p = p -> next;
    }
}

int main () { // this is what we we did to create the linked list

    int a[] = {3,5,7,10,15};

    create(a, 5);
    display(first);

    return 0;
}