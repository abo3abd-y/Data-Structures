#include <iostream>

using namespace std;

struct Node { 
    int data;
    Node *next;
}; 

Node *first = nullptr;
Node *last  = nullptr;

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

        if(i == (n - 1)) {last = t;}
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

Node *lsearchImproved (Node *p, int key) { // we need to understand this later because i forgot how this thing worked
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

void insert (int x, int pos) {
    Node *p;
    Node *t;

    if(pos == 0) { // create a node and then assign the next of it to be the first and first then assign to t
        t = new Node;
        t -> data = x;
        t -> next = first;
        first = t;
    }else if (pos > 0) {
        p = first;
        for(int i = 0; i < (pos - 1) && p; i++) {
            p = p-> next;
        }

        if(p) {
            t = new Node;
            t -> data = x;
            t -> next = p-> next;
            p-> next = t;
        }
    }
}

void insertLast (int x) { // this basically adds nodes in the end of linked lists
    Node *t = new Node;
    t -> data = x;

    if(!first) {
        first = t;
        last = t;
        t -> next = nullptr;
    }else {
        last -> next = t;
        last = t;
        t -> next = nullptr;
    }
}

void insertSorted (int x) { // we modified this so that it has a first node in the second argument
    Node *t = new Node;
    t -> data = x;
    if(!first) {
        t -> next = nullptr;
        first = t;
        last = t;  
    }else if(x <= first -> data){
        t -> next = first; // we fixed this mistake here; used to be  t -> next = first -> next;
        first = t;
        last = t -> next;
    }else {
        Node *p = first;
        Node *q = nullptr;

        while (p && x >= p-> data) {
            q = p;
            p = p -> next;
        }

        t -> next = q -> next;
        q -> next  = t;

        if(!p) {last = t;} // if p was the last position and t was bigger than all numbers
    }
}

void deleteNode(int pos) {
    Node *p = first;
    Node *q = nullptr;

    for(int i =0; i < (pos - 1) && p; i++) {
        q=p;
        p = p->next;
    }

    if(p) {
        if(p == first) {
            first = first -> next;
            delete p;
        }else if(p == last) {
            last = q;
            delete p;
            q -> next = nullptr;
        }else {
            q ->next = p -> next;
            delete p;
        }

    }


}

bool ifSorted(Node *p) {
    Node *q = p;
    int prev = INT32_MIN;

    while (q) {
        if(q -> data < prev) {
            return false;
        }
        prev = q -> data;
        q = q -> next;
    }

    return true;
}

void removeDuplicates (Node *src) {

    if(src) {
        Node *q = src;
        Node *p = q -> next;
        while (p) {
            if (p -> data != q -> data) {
                q =p;
                p = p-> next;
            }else {
                q -> next = p -> next;
                delete p;
                p = q -> next;
            }
        }
    }

}

void reverse(Node *src) {
    Node *p = src;
    Node *prev = nullptr;
    Node *prev_prev = nullptr;

    last = src;

    while (p) {
        prev_prev = prev;
        prev = p;
        p =  p -> next;
        prev -> next = prev_prev;
    }

    first = prev;

}

void rreverse(Node *p, Node *q) { // over here, we are not taking care of last pointer
    if(p) {
        rreverse(p -> next, p);
        p -> next = q;
    }else {
        first = q;
    }
}

Node * another_create (int a[], int n) { 
    int i;

    Node *t;

    Node *new_node = new Node;
    new_node -> data = a[0];
    new_node -> next = NULL;
    t = new_node;
    
    
    for(i =1; i < n;i ++) {
        t -> next = new Node;
        t = t-> next;
        t -> data = a[i];
        t -> next = NULL;

        if(i == (n - 1)) {last = t;}
    }

    return new_node;

}

void concatenate (Node *one, Node *two) { // last not taken care of
    Node *p = one;

    while (p->next) {
        p = p -> next;
    }

    p -> next = two;
}

void merge (Node *one, Node *two) { // merging mean we merge the two sorted lists together in sorted way. last is not being taken of
    if (one && two) {
        Node *last = nullptr;
      

        if (one -> data <= two -> data) {
            first = one;
            last = one;
            one = one -> next;
            
        }else {
            first = two;
            last = two;
            two = two -> next;
        }
        last -> next = nullptr;

        while (one || two) {
            /*
                4 cases:
                    1. one finishes out and all is left is two
                    2. two finishes out and all is left is one
                    3. one is <= two
                    4. two is >= one
            */
            if(one && (!two || (one -> data <= two -> data))) {
                last -> next = one;
                one = one -> next; // proceed
            }else {
                last -> next = two;
                two = two -> next; // proceed

            }

            last = last -> next; 
            last -> next = nullptr; 
        }
    }
}



int main () { 

    insertSorted(2);
    insertSorted(1);
    insertSorted(7);
    insertSorted(5);
    insertSorted(4);
    insertSorted(4);
    insertSorted(7);
    insertSorted(1);

    display(first);
    cout << endl;
    

    int a[] = {0,1,2,2,2,3,7,8,9,45};
    Node *another_first = another_create(a, 10);

    cout << endl;
    display(another_first);

    merge(first, another_first);

    cout << endl;
    display(first);

    return 0;
}