#include <iostream>

using namespace std;

int main () {

    int a[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    for(int i =0 ; i < 3 ; i ++ ) { // this is called row major because we are accessing elements from row to row
        for (int j = 0; j < 4 ; j ++ ){
            cout << a[i][j] << endl;
        }
    }

    return 0;
}