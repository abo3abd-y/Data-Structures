#include <iostream>
#include <cmath>
using namespace std;

struct Array {
    int A[15];
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

int BinarySearch (Array arr, int key) {
    int left = 0;
    int right = arr.length - 1;
    int middle;

    while (left <= right) {
        middle = floor((left + right)/2);
        if(arr.A[middle] == key){
            return middle;
        }else if(arr.A[middle] < key) {
            left = middle + 1;
        }else {
            right = middle - 1;
        }
    }

    return -1;
}

int main () {

    Array arr = {{4,8,10,15,18,21,24,27,29,33,34,37,39,41,43}, 15, 15};
    cout << BinarySearch(arr, 21) << endl;
    cout << BinarySearch(arr, 100) << endl;
    //sdisplay(arr);


    return 0;
}