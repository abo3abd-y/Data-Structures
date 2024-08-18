#include <iostream>

using namespace std;

// insertion sort is basically inserting elements by finding if the next element is bigger or not that is why it is called insertion algorithm

// in a linked list, we do not have to shift elements once we found the right spot, which is why it is considered better

// so now you understand, insertion sort basically starts 'adding' elements to the same list by widening the pointer and keep adding until the pointer is equal to size - 1

// max: n^2, min: n

void swap(int &x, int &y) { 
    int temp = y;
    y = x;
    x = temp;
}


void insertionSort (int a[], int size) {
    int j =0;
    for(int i = 0; i < size; i ++) {
        j = i;
        while((j - 1) >= 0 && a[j - 1] > a[j]) {
            swap(a[j-1],a[j]);
            j --;
        }
    }
}

void display(int a[], int size) {
    for(int i = 0; i < size; i ++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main () {

    int a[] = {5,8,7,3,2};
    int size = sizeof(a)/sizeof(a[0]);
    insertionSort(a, size);

    display(a, size);


    return 0;
}