#include <iostream>

using namespace std;

int sum (int n){
    if (n == 0) {
        return 0;
    }else {
        return n + sum(n - 1);
    }
}

int main() {

    cout << sum(5) << endl; // this is basically the sum function that we could have done with n(n + 1)/2 which is less efficient but this is for recursion function sake

    return 0;
}