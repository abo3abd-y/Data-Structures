#include <iostream>

using namespace std;

// so heap is basically a complete buinary tree where you cannot have another height unless all the children had their children

// also, you cannot have a complete binary tree unless the children are in subsequent order from left to right

// complete binary trees are represented by an array where an index has a left child at index i*2 and right child at index i*2 + 1

// which means that even numbers are left children and odd numbers are right children

// there are two kinds of heap functions: max heap and min heap

// max heap basically says that the children has lesser or equal valuea to the parents and vice versa

struct heap {
    int *a; // this is the array
    int size;
    int heapSize; // the last element of the array 
};

// we are using a struct-based heap as you can see to make things simpler

void insert (heap &a, int n) { // n is now the new value that is inserted
    if((a.heapSize + 1) < a.size) {
        int i = a.heapSize + 1;
        a.a[++a.heapSize] = n;
        

        while (i > 0 && n > a.a[i/2]) {
            a.a[i] = a.a[i/2];
            i /=2;
        }
        a.a[i] = n;
    }
    
}



// void create(int a[], int n) { // n is the size of the array and assuming that the array is already initialized
//     for(int i = 0; i < n; i ++) {
//         insert(a, i);
//     }

// }

void deleteHeap(heap &a) { // n represents the last element in the heap

    if(a.heapSize >= 0) {
        int last, i, j;
        last = a.a[a.heapSize--];
        i = 0;
        j = 1;
        a.a[0] = last;

        

        while(j  <= (a.heapSize)) {
            if((j + 1) <= (a.heapSize) ? a.a[j + 1] : -1 > a.a[j]) {
                j += 1;
            }

            if(a.a[j] > a.a[i]) { // we swap if thats the case
                int k = a.a[i];
                a.a[i] =a.a[j];
                a.a[j] = k;
                i = j;
                j = i*2; // the left child first
                continue;
            }
            break;
        }
    }
    
}

// when we delete from the heap, we delete the highest element (root) but move the last element as the firsrt element and keep moving it dowo and swapping it until 

void display(heap a) {
    for(int i = 0; i < a.heapSize + 1; i ++) {
        cout << a.a[i] << " ";
    }
    cout << endl;
}

int main () {
    heap h;
    h.a = new int[10];
    h.size = 10;
    h.heapSize = -1;
    insert(h, 0);
    insert(h, 10);
    display(h);

    insert(h, 20);
    insert(h, 30);
    insert(h, 25);
    insert(h, 5);
    insert(h, 40);
    insert(h, 35);

    display(h);
    
    return 0;
}

//NOTE: heap sort is basically when you delete an element, the element goes back to the end of the list but is nomt counted as heap 

// ANOTHER NOTE: Heap is not used for searching purposes; for inserting and deleting purposes

