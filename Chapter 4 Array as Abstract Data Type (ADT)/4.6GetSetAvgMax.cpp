#include <iostream>

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

int get(int index, Array arr) {
    if(index >=0 && index < arr.length) {
        return arr.A[index];
    }
    return -1;
}

void set(int index, int x, Array *arr) {
    if(index >=0 && index < arr -> length) {
        arr -> A[index] = x;
    }
}

int max(Array arr) {
    int max = 0;
    for(int i = 0; i < arr.length; i ++ ){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }
    return max;
}

int min(Array arr) {
    int min = 1000000;
    for(int i = 0; i < arr.length; i ++ ){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    }
    return min;
}

int sum(Array arr) {
    int total = 0;
    for(int i = 0; i < arr.length; i ++ ){
        total += arr.A[i];
    }
    return total;
}



int main () {

    Array arr = {{4,8,10,15,18,21,24,27,29,33,34,37,39,41,43}, 15, 15};
    
    set(3, 16, &arr);

    cout << get(1, arr) << endl  << max(arr) << endl << min(arr) << endl << sum(arr);
    return 0;
}