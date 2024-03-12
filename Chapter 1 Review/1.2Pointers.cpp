#include <iostream>
#include <stdlib.h> // this library allows us to access the stuff used in the c language

using namespace std;

int main() {

    int a = 10;

    int *p;

    p = &a; // we store the address of a at pointer p

    cout << a << endl;

    cout << *p << endl; // here we are accessing the values at a's address by dereferncing the value at a

    int *h =(int *) malloc(5 * sizeof(int)); // we want to store some values at the heap, and here are saying that we want to store 5 values with each having the bytes same as the integer. This is c style thing that we are using here

    // as you can see above, we use (int * ) to type cast the pointer since the malloc function returns a void pointer and we have to type cast it to an int pointer

    // by the way, we are using the c type of way to allocate some memory in the heap 

    int *h_alt = new int[5]; //as you can see here, we are using the c++ way of allocating memory in heap which is way simpler than the c type of way


    for(int i = 0; i < 5; i ++ ){
        h_alt[i] = i; // this is how you can access elements of a pointer using the bracekt notation [] that is also used for list things
    }

    for(int i = 0; i < 5; i ++ ){
        cout << h_alt[i] << endl;
    }

    free(h); // this is how you deallocate memory on the heap for c langauge

    delete []h_alt; // this is how you do it for c++

    // notice that you do not need to deallocate it right before the program ends because the program automatically do it for you but when the program is not ending and you no longer

    // need that heap memory, you must manualy need to deallocate the memory

    // notice that the pointer size is 8 bytes and it is independent of the data type of that pointer, the size will be 8 bytes for 64-bit machines.

    
    return 0;
}