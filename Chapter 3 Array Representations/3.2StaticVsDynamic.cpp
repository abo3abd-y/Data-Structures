#include <iostream>

using namespace std;

int main () {


    int a[5]; // the size of the arrya here is static because it is defined in compiler time and you cannot change the size of the array during runtime

    int n;

    cin >> n;

    int b[n]; // this is decided in runtime because we asked the size of the array from the user and we created an array out of it



    int *p;

    p = new int[5]; // as  you can see, we created an array of size 5 in the heap area

    p[0] = 1; // we can access pointers just like arrays

    delete []p; // here we are deleting the memory in p in order to avoid memory leak problems
    return 0;
}