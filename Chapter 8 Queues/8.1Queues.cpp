#include <iostream>
#include <vector>

using namespace std;

//queues have two ends: the front and the back
// in this file, we are using a queue that is based on vectors

class queue {
private:
    vector <int> qList = {};
    int front = -1;
    int rear = -1;

public:

    void enqueue(int x);
    void dequeue();
    bool isEmpty();
    void display();
    int accessFront();
    int accessRear();

};

void queue::enqueue(int x) {
    if(front == rear && qList.size() != 0) {
        front = rear = -1;
        qList[++rear] = x;
        return;
    }
    qList.push_back(x); // do not forget to use push back for vectors because we are not using lists
    rear++;
}

void queue::dequeue() {
    if(front != rear) {
        qList[++front] = -1;
    }
}

bool queue::isEmpty() {
    return rear == front ? true : false; // return true if rear == front else return false
}

void queue::display() {
    for(int i = front + 1; i<=rear; i ++) {
        cout << qList[i] << " ";
    }
    cout << endl;
}

int queue::accessFront() {
    return front;
}

int queue::accessRear() {
    return rear;
}


int main () {

    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    cout << q.accessFront() <<" " << q.accessRear() << endl;

    q.dequeue();
    q.dequeue();
    q.display();

    cout << q.accessFront() <<" " << q.accessRear() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    q.display();

    cout << q.accessFront() <<" " << q.accessRear() << endl;

    q.enqueue(10);
    q.display();

    cout << q.accessFront() <<" " << q.accessRear() << endl; // works perfectly well as you can see here with the results of these functions
    

    return 0;
}