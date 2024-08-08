#include <iostream>

using namespace std;

class Node {

public:
    int data;
    Node *next;

};

class LinkedList {

private:
    Node *first;
public:
    LinkedList() {first = NULL;}
    LinkedList(int a[], int n);
    ~LinkedList();

    void display ();
    void insert (int index, int x);
    int Delete(int index); // returns the deleted element
    int length();

};

LinkedList :: LinkedList(int a[], int n) {
    Node *newNode = new Node;
    Node *iterator;

    newNode -> data = a[0];
    newNode -> next = nullptr;
    first = newNode;
    iterator = newNode;

    for(int i = 1; i < n; i ++) { // this thing should work
        newNode = new Node;
        newNode -> data = a[i];
        newNode -> next = nullptr;
        iterator -> next = newNode;
        iterator = iterator -> next;
    }

}

void LinkedList :: display() {
    Node *p = first;
    while (p) {
        cout << p -> data << " ";
        p = p -> next;
    }

    cout << endl;
}

void LinkedList :: insert (int index, int x) {
    Node *q = new Node;
    q -> data = x;
    if (index == 0) {
        q -> next = first -> next;
        first = q;
    } else if(index >= 1 && index <= length() ) {
        Node *prev = first;
        Node *p = first;

        for(int i = 0; i < length() && p; i ++) {
            prev = p;
            p = p -> next;
        }
        q -> next = prev -> next;
        prev -> next = q;

    }
}


int LinkedList :: length () {
    Node *p = first;
    int counter = 0;

    while(p) {
        p = p -> next;
        counter ++; 
    }

    return counter;
}

int LinkedList :: Delete (int index) {
    if (index > 0 && index <= length()) {
        if (index == 1) {
            int x;
            Node *deleted = first;
            first= first -> next;
            x = deleted -> data;
            delete deleted;
            return x;
        }else {
            int x;
            Node *p = first;
            Node *prev = nullptr;
            for(int i = 0; i < (length() - 1); i ++) {
                prev = p;
                p = p -> next;
            }
            prev -> next = p -> next;
            x = p -> data;
            delete p;
            return x;
        }
    }
    return -1;

}

int main () {



    return 0;
}