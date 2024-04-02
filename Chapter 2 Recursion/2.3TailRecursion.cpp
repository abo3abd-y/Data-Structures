#include <iostream>

using namespace std;

void fun (int n) {
    if (n > 0) {
        cout << n << endl;

        fun(n - 1);
    }
} 
// tail recursion is basically a function that calls the function itself after the end of everything; the call of the function is at the end of the function and nothing is after

int main() {

    fun(3);

    return 0;
}