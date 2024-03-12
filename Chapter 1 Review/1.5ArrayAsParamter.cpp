#include <iostream>

using namespace std;

void fun (int a[], int n){ // as you can see, we are passing an array or rather a pointer to the first value to the array
    //also, we can also change the bracket notation to int *a, it will do the same thing and work perfectly
    for(int i = 0; i < n ; i ++){
        cout << a[i] << endl;
    }

    a[2] = 100;
}

int * another_fun (int n){ // we can also create and return arrays using functions that we define
    int *p = new int[5]; // we are allocating memory in the heap because when the function ends, the data that it used in the stack will be gone

    return p;
}
int main() {
    int a[5] = {1,2,3,4,5};

    fun(a, 5); // as you can see here, we are passing the address of the array to the function is basically what we are doing here


    cout << a[2] << endl; // as you can see, we changed the value of the array of the 3rd index inside the function because the paramter is basically a pointer


    int *b;

    b = another_fun(5); // we created a list of size 5 in the heap using a function that we created



    return 0;
}