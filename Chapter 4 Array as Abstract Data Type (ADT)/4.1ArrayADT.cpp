#include <iostream>

using namespace std;

struct Array {
    int *A;
    int size;
    int length; //number of elements in the array
};

void display (Array arr) {
    cout << "Elements are: " << endl;

    for(int i =0; i < arr.length ; i ++ ){
        cout << arr.A[i] << endl;
    }
}
int main () {
    Array arr;
    int n, i;
    cout << "Enter the size of your array: " << endl;
    cin >> arr.size;

    arr.A = new int[arr.size];

    arr.length = 0; // this kind of array creation is preferable because the array here is dynamic as you can see

    cout << "Enter the number of numbers: " << endl;
    cin >> n;


    cout << "Enter all elements for your array: " << endl;
    for(i =0 ; i< n; i ++ ){
        cin >> arr.A[i];
    }

    arr.length = n;

    display(arr);

    
    return 0;
}