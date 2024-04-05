#include <iostream>

using namespace std;

int main () {

    int *p = new int[5];

    for (int i = 0; i < 5; i ++){
        p[i] = i; // we are just assigning new values to the list that we just created
    }

    int *q = new int[10]; // we created a new array of double the size of p because p is not filled up and it needs a new array of a bigger size

    for (int i = 0; i < 5; i ++){
        q[i] = p[i]; // here we are copying the values of p into q because the size of p is at maximum
    }

    delete []p; // now we do not need that old array of size 5

    p = q; // now p points to the new array that q is now pointing to

    q = NULL; // now q is not pointing anywhere

    for(int i =0; i < 10; i ++){
        cout << p[i] << endl;
    }

    return 0;
}