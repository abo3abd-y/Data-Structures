#include <iostream>

using namespace std;

int j = 0; // global variable j is used in the third functino to demonstrate the use of global variables in recursive functions

int fun(int x) { // now we do something different here: we are returning and also we are doing something once the value is returned. We add x to the value returned then return it if needed

    if (x > 0) {
        return fun(x - 1) + x;

    }
    return 0;
}
// this should print something like fun(3) : 1 3 6 10 ... which basically increments each number and changes the variable

int another_fun (int n) {
    static int x = 0; // static variables are basically variables that can be accessed anywhere inside the function and where only one copy of it is made unlike normal variables
     // though after the function ends, the scope of it ends and the variable no longer exists
    if (n > 0) {
        x += 1;
        return another_fun(n - 1) + x;
    }
    return 0;
}

int global_var (int x) {
    if(x > 0) {
        j ++ ;
        return global_var(x - 1) + j;

    }
    return 0;
}
int main() {

    cout << fun(3) << endl; // this function should return 6
    cout << another_fun(3) << endl; // this function should return 9 
    cout << global_var(3) << endl << global_var(3) << endl; // the first one is 9 but then the second one is 18 because the global variable does not reset itself each time the function gets called but continues on unlike static variables
    return 0;
}