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

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int linearSearch(Array *arr, int key) {
    for(int i =0 ; i < arr->length ; i ++ ){
        if(key == arr->A[i]){
            swap(arr -> A[i],arr->A[i - 1]); // here we are the position of the found element by 1 so it is more likley to be found
            return i - 1;
        }
    }
    return -1;
}

int main () {

    Array arr = {{5,3,10,20,15, 2, 9, 7, 12, 3}, 10, 10};
    cout << linearSearch(&arr, 20) << endl;
    display(arr);


    return 0;
}