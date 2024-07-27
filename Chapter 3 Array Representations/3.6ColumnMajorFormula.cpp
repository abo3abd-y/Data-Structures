#include <iostream>

using namespace std;

int main () {

    

    int a[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    for(int i =0 ; i < 4 ; i ++ ) { // this is called column major because we are accessing elements from column to column but this is time consuming because that is not how elements are represented in the array
        for (int j = 0; j < 3 ; j ++ ){
            cout << a[j][i] << endl;
        }
    }
    return 0;
}