#include <iostream>

using namespace std;

void funA(int n); // we have this so that we do not have any confusion 
void funB(int n);

void funA (int n) {
    if(n > 0) {
        cout << n << endl;

        funB(n - 1);
    }
}

void funB (int n) {
    if (n > 1) {
        cout << n << endl;

        funA(n/2);
    }
}

// the above is called indirect recursion because you basically have two functions calling each other resulting in a cycle which is essentially a recursion function as you can 

// infer from the above functions



int main() {

    funA(10);

    return 0;
}