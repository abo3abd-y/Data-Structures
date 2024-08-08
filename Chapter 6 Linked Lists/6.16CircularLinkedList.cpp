#include <iostream>

using namespace std;

struct Node { 
    int data;
    Node *next;
}; 

Node *head = nullptr;

void create(int a[], int n) { // that is how you create a circular linked list; they are not entirely new concepts but they are important to learn
    Node *newNode = new Node;
    newNode -> data = a[0];
    newNode -> next = newNode;
    head = newNode;
    Node *p  = newNode;

    for(int i = 1; i < n; i ++) {
        newNode = new Node;
        newNode -> data = a[i];
        p -> next = newNode;
        newNode -> next = head;
        p = p -> next;
    }
}

void displayCircular (Node *p) { // if the linked list is circular, then use this loop to display the elements

    if(p) {
        Node *q = p;
        do { // do while loops run at least one as you can see here regardless whether they agree with the conditions or not
            cout << q -> data << " ";
            q = q -> next;

         }while(q != p);

    }
    cout << endl;
    


}

int length(Node *p) {
    Node *iterator = p;

    int x = 0;

    if(p) {
        do {
            iterator = iterator -> next;
            x ++;
        }while (iterator != p);
        return x;

    }
    return 0;
}

void insert (int position, int x) {
    if(!head) { // head is a nullptr
        Node *newNode = new Node;
        newNode -> data = x;
        newNode -> next = newNode;
        head = newNode;
    }else if(position >= 0 && position <= length(head)) {
        Node *p = head;
        for(int i = 0; i < (position - 1); i ++) {
            p = p -> next;
        }

        Node *newNode = new Node;
        newNode -> data = x;

        if(position == 0) {
            p = head;

            while (p -> next != head) { // as you can see we are trying to find the last node so that we can point it to the new start node
                p = p -> next;
            }
            p -> next = newNode;
            newNode -> next = head;
            head = newNode; // changing head is based on your preference because it will be the same anyways

        }else {
            newNode -> next = p -> next;
            p -> next = newNode;
        }
    }
}


int main () { 

    int a[] = {10,20,30,40,45,50};
    create(a, 6);
    displayCircular(head); // works perfectly as you can see here

    

    insert(2,25);
    displayCircular(head);

    insert(0, 5);
    displayCircular(head);

    insert(8, 65);
    displayCircular(head); // as you can see, this works perfectly for all other cases even the edge cases
  

    return 0;
}