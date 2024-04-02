#include <iostream>

using namespace std;

void fun (int n ) {
    if(n > 0){
        fun(n - 1);

        cout << n << endl;
    }
}
// as you can see in head recursion, the call of the function happens first and everything else happen after

// so it does everything after the return time

// head recursion cannot be easily converted into a loop just like tail recursion and how easy it is to convert it into a loop


int main() {

    return 0;
}