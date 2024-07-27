#include <iostream>

using namespace std;

struct Node { 
    int data;
    Node *next;
}*first; 

void create (int a[], int n) { 
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

void display (Node *p) { 
    while (p != NULL) {
        cout << p -> data << endl;
        p = p -> next;
    }
}

void rdisplay (Node *p) { // this is the recursive part of the display function where we basically converted the non-recursive part to the recursive part
    if(p != NULL) {
        cout << p-> data << endl;
        rdisplay(p->next);
    }
}

int main () { 

    int a[] = {3,5,7,10,15};

    create(a, 5);
    rdisplay(first);

    return 0;
}