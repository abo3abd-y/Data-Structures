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

void rdisplay (Node *p) { 
    if(p != NULL) {
        cout << p-> data << endl;
        rdisplay(p->next);
    }
}

int count (Node *p){
    int l = 0;

    while (p) {
        l ++;
        p = p -> next;
    }
    return l;
}

int rcount (Node *p){
    if (p != NULL) return rcount(p -> next) + 1;
    else  return 0;
}

int sum (Node *p) {
    int s = 0;
    while (p != NULL) {
        s = s + p -> data;
        p = p -> next;
    }
    return s;
}

int rsum (Node *p) {
    if(p == NULL) {
        return 0;
    }else{
        return rsum(p->next) + p->data;
    }
}

int main () { 

    int a[] = {3,5,7,10,15};

    create(a, 5);
    
    cout << "Length of the linked list is " << count(first) << endl;
    cout << "Length of the linked list is (using recursive count) " << rcount(first) << endl;

    cout << "The sum of all elements in linked list is " << sum(first) << endl;
    cout << "The sum of all elements in linked list is (using recursive rsum) " << rsum(first) << endl;


    return 0;
}