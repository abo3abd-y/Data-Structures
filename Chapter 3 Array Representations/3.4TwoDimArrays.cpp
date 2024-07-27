#include <iostream>

using namespace std;

int main () {
    int a[3][4]; //3 by 4 which means there are 3 rows and 4 columns

    // the array will be stored as a one dimensional array even though it is a 2 dimensional array

    int b[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}}; // as you can see, we created and intialized an array of size 3 by 4

    // third way of doing it here

    int *c[3]; // it is an array of pointers that point to an array of 4 elements in the heap

    c[0] = new int[4];
    c[1] = new int[4];
    c[2] = new int[4];

    c[0][1] = 2; // as you can see here, we are accessing the elements as if they were just arrays because we know that they are just arrays


    int **d; // so this is a pointer of a pointer

    d = new int*[3]; // we created an array of pointers in the heap
    d[0] = new int[4]; // they themselves are an array of size 4
    d[1] = new int[4]; // they themselves are an array of size 4
    d[2] = new int[4]; // they themselves are an array of size 4



    return 0;
}