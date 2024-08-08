#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class queue {

private:
    Node *front = nullptr;
    Node *back = nullptr;
public:
    void enqueue(int x);
    void dequeue();
    bool isEmpty();
    void display();

};

void queue::enqueue(int x) {
    Node *newNode = new Node;
    newNode -> data = x;
    newNode -> next = nullptr;

    
    if(!back) { // if it is empty then we do this
        front = back = newNode;
    }else {
        back -> next = newNode;
        back = back -> next;
    }
}

void queue::dequeue() {
    if(front) { // this just means if front is not a nullptr
        Node *placeholder = front;
        back = (front == back) ? nullptr : back;
        front = (front == back) ? nullptr : front -> next;
        delete placeholder;
    }
}

void queue::display() {
    Node *p = front;

    while(p) {
        cout << p -> data << " ";
        p = p-> next;
    }
    cout << endl;
}

int main () {

    queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(60);
    q.enqueue(70);
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(10);
    q.display(); // works perfectly as you can see which is a good thing as you can see here


    return 0;
}