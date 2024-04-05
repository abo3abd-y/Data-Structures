#include <iostream>

using namespace std;

int main() {
    int a[5]; // elements will be garbage

    int b[5] = {2,4,6,8,10};

    int c[5] = {2,4,6}; // the rest of the values will be initialized to zero if you initialized a part of the array as you can see


    int d[] = {1,2,3}; // even though we never mentioned the size of the array, the compiler knows that the size of the array is 3 and the array size is indeed 3

    b[0] = 10; // this is how you can access the elements in the array

    3[b] = 20; // we can also access the elements in the array by using this method here

    *(a + 1) = 2; // we can also access the elements of the array by using the pointer method

    

}