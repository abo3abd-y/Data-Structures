#include <iostream>

class Deque { // so this is the queue definition that i got from chatgpt (you should not do things like this but i had to after spending hours trying to implement a dequeue)
private:
    int *arr;           // Array to store elements
    int front, rear;    // Pointers to the front and rear
    int size;           // Maximum size of the deque
    int count;          // Current number of elements

public:
    Deque(int n) : size(n), front(-1), rear(0), count(0) {
        arr = new int[size];
    }

    ~Deque() {
        delete[] arr;
    }

    // Check if the deque is full
    bool isFull() {
        return count == size;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return count == 0;
    }

    // Insert element at the front
    void insertFront(int key) {
        if (isFull()) {
            std::cout << "Overflow\n";
            return;
        }

        // Circular increment
        front = (front - 1 + size) % size;
        arr[front] = key;
        count++;
    }

    // Insert element at the rear
    void insertRear(int key) {
        if (isFull()) {
            std::cout << "Overflow\n";
            return;
        }

        arr[rear] = key;
        rear = (rear + 1) % size;
        count++;
    }

    // Delete element from the front
    void deleteFront() {
        if (isEmpty()) {
            std::cout << "Underflow\n";
            return;
        }

        front = (front + 1) % size;
        count--;
    }

    // Delete element from the rear
    void deleteRear() {
        if (isEmpty()) {
            std::cout << "Underflow\n";
            return;
        }

        rear = (rear - 1 + size) % size;
        count--;
    }

    // Get the front element
    int getFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Get the rear element
    int getRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return -1;
        }
        return arr[(rear - 1 + size) % size];
    }
};

int main() {
    int n = 5;
    Deque dq(n);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(2);

    std::cout << "Front element: " << dq.getFront() << std::endl;
    std::cout << "Rear element: " << dq.getRear() << std::endl;

    dq.deleteFront();
    dq.deleteRear();

    std::cout << "After deletion, Front element: " << dq.getFront() << std::endl;
    std::cout << "After deletion, Rear element: " << dq.getRear() << std::endl;

    return 0;
}
