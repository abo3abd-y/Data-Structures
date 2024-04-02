#include <iostream>

using namespace std;


int fun (int n) {
    if(n > 100) {
        return n - 10;
    }else {
        return fun(fun(n + 11));
    }
}

// the above is meaningless but it is basically a nested recursion because when it calls itself, its argument is another call of itself as seen in the above function


int main() {

    int x = fun(95); // this shoudl return the number 91 after you call everything and after everything returns everything

    cout << x << endl; // this should return the value of 91 if the value is less than some certain value the value that is passed and return something else if the value is bigger than the certain value

    

    return 0;
}