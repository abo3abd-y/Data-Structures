#include <iostream>

using namespace std;

// so heap is basically a complete buinary tree where you cannot have another height unless all the children had their children

// also, you cannot have a complete binary tree unless the children are in subsequent order from left to right

// complete binary trees are represented by an array where an index has a left child at index i*2 and right child at index i*2 + 1

// which means that even numbers are left children and odd numbers are right children

// there are two kinds of heap functions: max heap and min heap

// max heap basically says that the children has lesser or equal valuea to the parents and vice versa

void insert (int a[], int n) { // this insert function is basically the max heap insert function
    int temp, i = n;
    temp = a[n];

    while (i > 0 && temp > a[i/2]) {
        a[i] = a[i/2];
        i /=2;
    }
    a[i] = temp;
}

// insert takes log n time 

// as you can see, the condition is that i > 0 because once it is 0, then we cannot compare no more because i/2 is just 0 and that wuill end in infinite loop



int main () {
    int a[8] = {0,10,20,30, 25,5,40,35};


    insert(a, 0);
    insert(a, 1);
    insert(a, 2);
    insert(a, 3);
    insert(a, 4);
    insert(a, 5);
    insert(a, 6);
    insert(a, 7);
    

    for(int i = 0; i < 8; i ++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}