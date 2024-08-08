#include <iostream>

using namespace std;

struct Node {
    Node *prev;
    int data;
    Node *next;
}*first = NULL;

void create (int a[], int n) {
    Node *newNode = new Node;
    Node *p;
    newNode ->prev = nullptr;
    newNode -> next = nullptr;
    newNode -> data = a[0];
    first = newNode;
    p = newNode;

    for(int i = 1; i < n; i ++) {
        newNode = new Node;
        newNode -> prev = p;
        newNode -> next = nullptr;
        newNode -> data = a[i];
        p -> next = newNode;
        p = p -> next;
    }
}

void display(Node *p) {
    while(p) {
        cout << p->data << " ";
        p = p -> next;
    }
    cout << endl;
}

int length(Node *p) {
    int x = 0;
    while(p) {
        p = p -> next;
        x++;
    }
    return x;

}

void insert(int position, int x) {
    if(!first || position == 0) {
        Node *newNode = new Node;
        newNode -> prev = nullptr;
        newNode -> data = x;
        
        if(!first) { // if the linked list is empty
            newNode -> next = nullptr;
            first = newNode;
        }else { //otherwise
            newNode -> next = first;
            first -> prev = newNode;
            first = newNode;
        }
    }else if(position >=1 && position <= length(first)){
        Node *p = first;
        for(int i = 0; i < (position - 1); i ++ ) {
            p = p -> next;
        }
        Node *newNode = new Node;
        newNode -> data = x;
        newNode -> next = p -> next;
        newNode -> prev = p;
        p -> next = newNode;

        if(position == length(first)) {return;}
        p-> next -> prev = newNode;
        
        
    }
}

int main () {

    int a[] = {10,20,30,40,50};
    create(a, 5);
    display(first);

    cout << "length is " << length(first) << endl;

    insert(0,5);
    display(first);

    insert(3,25);
    display(first);

    insert(7, 55);
    display(first); // i think it works perfectly as you can see here

    return 0;
}