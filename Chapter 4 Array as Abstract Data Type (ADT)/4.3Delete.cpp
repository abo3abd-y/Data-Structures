#include <iostream>

using namespace std;

struct Array {
    int A[10];
    int size;
    int length; //number of elements in the array
};

void display (Array arr) {
    cout << "Elements are: " << endl;

    for(int i =0; i < arr.length ; i ++ ){
        cout << arr.A[i] << endl;
    }
}

void append (Array *arr, int x) {
    if(arr->length < arr->size) // we check the element 
        arr ->A[arr->length ++ ] = x;
}

void insert (Array *arr, int index, int x) {
    if(index >= 0 && index <= arr->length && arr->length < arr->size) {
        for(int i = arr->length; i > index; i --){
            arr->A[i] = arr->A[i - 1]; // moving old elements to the right basically 
        }
        arr->A[index] = x;
        arr->length ++;
    }
}

void Delete (Array *arr, int index) {
    if(index < arr -> length && index >= 0){
        for(int i = index ; i < arr -> length - 1; i ++){
            arr -> A[i] = arr -> A[i+1]; // we basically move things from right to left as opposed to the insert method which move things from left to right
        }
        arr -> length --;
    }
}


int main () {

    Array arr = {{5,3,10,20,15}, 10, 5};

    append(&arr, 0); // as you can see, it worked
    display(arr);

    cout << "********************" << endl;

    insert(&arr, 1, 100);
    display(arr);


    cout << "********************" << endl;

    Delete(&arr, 3);
    display(arr);


    return 0;
}