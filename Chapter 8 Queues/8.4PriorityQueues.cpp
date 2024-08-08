#include <iostream>

using namespace std;

class priorityQueues {

private:
    int *lst;
    int count; // keeps track of how many elements there are in the list
    int front;
    int back;
    int size;
public:

    priorityQueues(int x);
    void enqueue(int x);
    void dequeue();
    void display();
    

};

priorityQueues :: priorityQueues(int x) {
    size = x;
    front = back = -1;
    count = 0;
    lst = new int[size]; // initialize the list as you can see here  
}

void priorityQueues :: enqueue(int x) {
    if(size != 0 && (count + 1) <= size) {
        int index = (front + 1) % size; // the start of the array is
        int counter = 0;
        while (index != ((back + 1) % size)) { // we need to figure out which index we are inputting this new number in. the reaon why we do back + 1 is beacuse we actually want to check the last element
            
            if(x < lst[index]) {
                break;
            }
            index = (index + 1) % size;
            counter ++;
        }


        counter = count - counter;
        int j = 0;
        for(int i = (back + 1) % size; j != counter; i = (i - 1 + size) % size) { // as you can see, we have modulus everywhere because our array is a cycle as you can see
            lst[i] = lst[(i - 1 + size) % size];
            j++;
            
        }

        if(x > lst[back]) { // assign the new numbers here
            lst[(back + 1) % size] = x;
        }else{
            lst[index] = x;
        }
        
       

        // do not forget to increment these numbers
        count ++;
        back = (back + 1) % size; 
    } 
}

void  priorityQueues :: dequeue() {
    if(count > 0) {
        front = (front + 1) % size;
        lst[front] = -1;
        count --;
    }
}

void priorityQueues :: display() {
    if(count > 0) {
        int i =0;
        int shifter = (front + 1) % size;
        while(i != count ) {
            if(shifter!= -1 && lst[shifter] != - 1) {
                cout << lst[shifter] << " ";
            }
            shifter = (shifter + 1) % size;
            i ++;

        }

        cout << endl;
        //cout << lst[i] << endl;
    }
}

int main () {

    priorityQueues p(10);
    p.enqueue(20);
    p.enqueue(30);
    p.enqueue(10);
    p.display();

    p.dequeue();
    p.dequeue();
    p.display();

    p.enqueue(5);
    p.enqueue(17);
    p.enqueue(34);
    p.enqueue(25);
    p.enqueue(100);
    p.enqueue(12);
    p.enqueue(2);
    p.enqueue(16);
    p.enqueue(45);
    p.display();


    p.dequeue();
    p.dequeue();
    p.dequeue();
    p.display(); 



    p.enqueue(7);
    p.enqueue(20);
    p.enqueue(33);
    p.display(); // as you can see, this now works perfectly as expected after many hours

    p.enqueue(98); // edges cases work as you can see here
    p.display();

    return 0;
}