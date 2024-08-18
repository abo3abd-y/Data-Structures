#include <iostream>

using namespace std;

// the most famous technique, quick sort

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





int main () {
    int a[] = {30,70,20,60,90,10,80,25};
    int size = sizeof(a)/sizeof(a[0]);
    partition(a, 0, 7);

    display(a, size); // as yuo can see, this works perfectly which is what expected
    return 0;

    return 0;
}