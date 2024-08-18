#include <iostream>

using namespace std;

void swap(int &x, int &y) { 
    int temp = y;
    y = x;
    x = temp;
}

void bubbleSort(int a[], int size) { 
    int lastIndex = size - 1; // first index iterator
    int i = 0; // second index iterator
    int flag = 0; // this is a variable that breaks out of the while loop if the array is already sorted in the first inner iteration
    while(lastIndex) {
        while(i != (lastIndex) && (i + 1) < size) {
            if(a[i] > a[i + 1]) {
                swap(a[i + 1], a[i]);
                flag ++;
            }
            i ++;
        }
        lastIndex--;
        i= 0;
        if(!flag) {break;}
    }
        
}

// bubble sort works by basically moving the largest elements to the end of the array by comparing them to the next element

// if the element is not bigger than the next element, then we just simply move on to this next larger element and keep going on with the algorithm


// time complexity: n^2 and more specifically n(n-1)/2 time but the minimum is o(n)

// thus max: n^2, min: n

// NOTE: you can use bubble sort to find nth maximum number by changing a little with the bubble sort. you can do that by changing the while(lastIndex) condition


void display(int a[], int size) {
    for(int i = 0; i < size; i ++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main () {
    int a[] = {5,8,7,3,2};
    int size = sizeof(a)/sizeof(a[0]);
    bubbleSort(a, size);

    display(a, size);
    

    return 0;
}