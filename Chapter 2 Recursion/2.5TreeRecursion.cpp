#include <iostream>

using namespace std;

void fun(int n ) {
    if (n > 0) {
        cout << n << endl;

        fun(n - 1);
        fun(n - 1);
    }
}
// a tree recursion is a function that calls itself more than once in the same function 
int main() {

    fun(3);
    return 0;
}