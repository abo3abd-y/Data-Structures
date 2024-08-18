#include <iostream>

using namespace std;

void swap(int &x, int &y) { 
    int temp = y;
    y = x;
    x = temp;
}

void display(int a[], int size) {
    for(int i = 0; i < size; i ++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void selectionSort(int a[], int size) {
    int k;
    for(int i = 0; i < size; i ++) {
        for(int j = k = i; j < size; j ++) {
            if(a[j] < a[k]) {
                k = j;
            }
        }
        swap(a[i], a[k]);
    }
}

// max: n^2, swap: n unlike other methods which is the only algorithm that does this in the minimum sense since we are using an extra pointer

// because we are basically saying that if the loop ended then only then do we actually swap which is important

// selection basically chooses a number and choosing whether the next elements are smaller; if they are, then move k to this pointer, otherwise move on

// after the loop ends, swap i with k and incremenet i and then repeat the procedure

// similarly to bubble sort algorithm, here we can get kth smallest element if we wanted to

int main () {

    int a[] = {5,8,7,3,2};
    int size = sizeof(a)/sizeof(a[0]);
    selectionSort(a, size);

    display(a, size); // as yuo can see, this works perfectly which is what expected
    return 0;
}