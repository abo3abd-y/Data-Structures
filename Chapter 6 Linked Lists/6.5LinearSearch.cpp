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

int max (Node *p) {
    int max = INT32_MIN;

    while (p) {
        if(p->data > max) {
            max = p -> data;
        }
        p = p ->  next;
    }
    return max;
}

int rmax (Node *p) {
    int max = 0;
    if(p == NULL){
        return INT32_MIN;
    }else {
        max = rmax(p -> next);
        if(max > p -> data) return max;
        else return p -> data;
    }
}

Node * lsearch (Node *p, int key) {

    while (p) {
        if(key == p -> data) {
            return p;
        }
        p = p -> next;
    }
    return NULL;
}

Node * lrsearch(Node *p, int key) {
    if(p == NULL) {
        return NULL;
    }else{
        if(key == p->data){
            return p;
        }else{
            return lrsearch(p -> next, key);
        }
    }
}

Node *lsearchImproved (Node *p, int key) {
    Node *q;
    while (p) {
        if(key == p -> data) { // in here, we moved the element that we found to the first element in the linked list by swapping them with the first element in the list
            q->next = p-> next;
            p -> next = first;
            first = p;
            return p;
        }
        q = p;
        p = p -> next;
    }
    return NULL;
}
int main () { 

    int a[] = {3,5,7,10,15};

    create(a, 5);

    cout << "The linear search of 5 is " << lsearch(first, 5) -> data << endl; // this will give you an error if the key is not found because it will return a null
    cout << "The linear search of 5 is (using the recursive part) " << lrsearch(first, 5) -> data << endl;
    cout << "The linear search of 5 is (using the improved one) " << lsearchImproved(first, 5) -> data << endl;

    display(first); // as you can see, 5 is moved to the front
    


    return 0;
}