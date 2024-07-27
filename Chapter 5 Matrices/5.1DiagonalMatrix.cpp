#include <iostream>

using namespace std;

// diagonal matrix have the same number of rows as column; that is, it should be n x n and 

// the diagonal part of the matrix should be a non-zero number and the rest zero

struct Matrix {
    int A[10];
    int n;
};

void set (Matrix *a, int i, int j, int x) { // i and j being the indices and x is the number to set
    if(i == j) {
        a->A[i - 1] = x;
    } // that is it basicallt
}

int get(Matrix a, int i, int j){
    if(i == j) return a.A[i - 1]; // as you can see, we just return the diagonal value 
    else return 0; // otherwise we return 0
}

void display (Matrix a) {
    for(int i =0; i < a.n; i ++) {
        for(int j =0; j < a.n ; j ++){
            if(i == j) cout << a.A[i - 1] << endl;
            else cout << "0" << endl;
        }
    }
}
int main () {

    Matrix a;
    a.n = 4;

    set(&a, 1,1,5);
    set(&a, 2,2,8);
    set(&a, 3,3,9);
    set(&a, 4,4,12);

    display(a);
    return 0;
}