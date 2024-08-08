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
    p = first;

    for(int i = 1; i < n; i ++) {
        newNode = new Node;
        newNode -> data = a[i];
        newNode -> prev = p;
        newNode -> next = nullptr;
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



void Delete(int position) {
    if(first) {
        if(position == 1) {
            Node *t = first;
            first = first -> next;
            if(first) {first -> prev = nullptr;} // only if first's new next is available and not as null. in other words, only if the linked list's size is greater than 1
            delete t;
        }else {
            Node *p = first;
            Node *q = nullptr;
            for(int i = 0; i < (position - 1); i ++) {
                q = p;
                p= p -> next;
            }
            q -> next = p -> next;

            if(p -> next) {p -> next -> prev = q;} // if the node that is to be deleted is not the last node
            delete p;
        }
    }
}

void reverse(Node*& start) { // as you can see here, we are using the reference of a pointer
    if(start) {
        Node *p = start;
        Node *placeholder = nullptr;
        while(p -> next) {
            placeholder = p -> next;
            p -> next = p -> prev;
            p -> prev = placeholder; 
            p = p -> prev; // do not forget this part; you assume p = p -> next which is incorrect beacuse we already switched them up before this with q
        }
        p -> next = p -> prev; // takes care of the last pointer if you know what i mean
        p -> prev = nullptr;
        start = p;
    }
    
}

int main () {

    int a[] = {10,20,30,40,50};
    create(a, 5);
    display(first);

    reverse(first);
    display(first);

    

    return 0;
}






/*
    Linked list vs arrays:
        1. insert: inserts for linked lists are generally cheaper in terms of time because arrays, especially when you have large bytes like a whole ass student record
            then it requires a lot of bytes to move those bytes from left to right if you want to move those records for insertion. In linked lists, we do not need to shift anything
            unlike arrays which is why linked lists win in this case.
        2. accessing elements on the fly: for searching, arrays are faster because it just requires o(1) to get that a specific element whereas linked lists you need to traverse the list to get to the
            desired number or position in the linked list.
        3. space: arrays require less space because linked lists have the values as well as the pointer to the next position.
        4. delete: the time is the same for the both if you think about it unless when arrays have more bytes, then linked lists are more efficient if you think about it.
        5. search: arrays are more efficient because you can do binary search to get a specific element if the array was in ascending order. in linked lists, you can only do 
            linear search because it is a sequential type of data. you can do binary search in linked lists, but it will require n long n time because when you divide, you have to go 
            to the middle element by linearly going there unlike arrays.
        

        if you want variable length, then linked list is good for you. if data size is important for you, then linked lists are good for you.

*/