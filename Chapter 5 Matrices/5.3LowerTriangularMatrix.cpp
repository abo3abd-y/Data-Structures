#include <iostream>

using namespace std;



struct Matrix {
    int *A;
    int n;
};

void set (Matrix *a, int i, int j, int x) { // i and j being the indices and x is the number to set
    if(i >= j) {
        a->A[i * (i - 1)/2 + j - 1] = x;
    }
}

int get(Matrix a, int i, int j){
    if(i >= j) return a.A[i * (i - 1)/2 + j - 1]; 
    else return 0; 
}

void display (Matrix a) {
    for(int i =0; i < a.n; i ++) {
        for(int j =0; j < a.n ; j ++){ // it works perfeclty when i set i and j to 0 instead of 1 as instructed in the video 
            if(i >= j) cout << a.A[i * (i - 1)/2 + j - 1] << " ";
            else cout << "0" << " ";
        }
        cout << endl;
    }
}
int main () {

    Matrix a;
    cout << "Enter dimensions: " << endl;
    cin >> a.n;
    a.A = new int[(a.n * (a.n + 1))/2];

    for(int i = 0 ; i < a.n;i ++) {
        for(int j = 0; j < a.n; j ++ ) {
            set(&a, i,j,i + j);
        }
    }

    display(a);
    return 0;
}