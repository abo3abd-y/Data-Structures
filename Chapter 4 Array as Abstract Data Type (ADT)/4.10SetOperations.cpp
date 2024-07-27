#include <iostream>

using namespace std;

struct Array {
    int A[30];
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

void reverse (Array *arr) {
    int temp[arr -> length];
    int i,j;
    for(i = arr->length - 1, j= 0; i>=0;i --, j++){
        temp[j] = arr->A[i];
    }

    for(int i = 0; i < arr->length;i ++) {
        arr -> A[i] = temp[i];
    }
}

void another_reverse (Array *arr) {
    int i, j;
    int temp = 0;
    for(i = arr -> length - 1, j = 0; i != j ; i -- , j ++){
        temp = arr -> A[j];
        arr -> A[j] = arr -> A[i];
        arr-> A[i] = temp;
    }
}

void insertSorted (Array *arr, int x) { // insert this when the array is sorted
    if(arr -> length < arr -> size) {
        int i = arr -> length - 1;
        while (x < arr -> A[i]) {
            arr -> A[i + 1] = arr -> A[i];
            i --;
        }
        arr -> A[i + 1] = x;
        arr -> length ++;
    }

}

bool isSorted (Array arr) {
    for (int i = 0; i < arr.length - 1; i ++) {
        if(arr.A[i] > arr.A[i + 1]) 
            return false;
        
    }
    return true;
}

void balance (Array *arr) {
    int i =0;
    int j = arr -> length - 1;
    int temp = 0;

    while (i < j) {
        while(arr -> A[i] < 0) {i ++;}
        while(arr -> A[j] >= 0) {j --;}
        if(i < j) {
            temp = arr -> A[j];
            arr -> A[j] = arr -> A[i];
            arr -> A[i] = temp;
        }
        
    }
}

Array * Merge (Array arr1, Array arr2) {
    Array *arr3 = new Array();

    int i =0;
    int j =0;
    int k =0;

    while (i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            arr3->A[k ++] = arr1.A[i ++];
        }else{
            arr3->A[k ++] = arr2.A[j ++];
        }
    }
    for(; i < arr1.length; i ++){
        arr3->A[k ++] = arr1.A[i];
    }
    for(; j < arr2.length; j ++){
        arr3->A[k ++] = arr1.A[j];
    }
    arr3->length = arr1.length + arr2.length;

    return arr3;
}

Array * intersection (Array arr1, Array arr2) {
    Array *arr3 = new Array();

    int i =0;
    int j =0;
    int k =0;

    while (i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            i++;
        }else if(arr1.A[i] > arr2.A[j]){
            j++;
        }else{
            arr3 -> A[k ++] = arr1.A[i ++];
            j ++;
        }
    }
    arr3->length = k;

    return arr3;
}

Array * difference (Array arr1, Array arr2) {
    Array *arr3 = new Array();

    int i =0;
    int j =0;
    int k =0;

    while (i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            arr3 -> A[k ++] = arr1.A[i ++];
        }else if(arr1.A[i] > arr2.A[j]){
            j++;
        }else{
            i++;
            j++;
        }
    }
    for(; i < arr1.length; i ++){
        arr3->A[k ++] = arr1.A[i];
    }
    arr3->length = k;

    return arr3;
}

int main () {

    Array arr1 = {{4,8,10,15,18,21,24,27,29,33,34,37,39,41,43, 46, 47}, 30, 17};
    Array arr2 = {{2,8,10,12,15,43}, 30,6};

   Array *arr3 = intersection(arr1, arr2); // basically finds what is common in the two arrays
   Array *arr4 = difference(arr1, arr2);
   display(*arr3);
   display(*arr4);

    return 0;
}