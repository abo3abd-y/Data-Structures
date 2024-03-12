#include <iostream>

using namespace std;

int main() {

    int x = 10;

    int &r = x; // references must be intialized when first declared

    // notice that references are basically two names of the same variables. In this case, r is the same thing as x and both ooccupy the same address

    x ++;

    cout << r << endl; // as you can see, it worked

    // why would you need another name of the same variable? This is very useful in paramter passing which we will explain later on

    // NOTE: references must be intialized when declared because otherwise you will get an error

    int y =30;

    r = y;

    cout << x << endl;

    // as you can see, even if we change the value of r, the parent variable of x will also change as well 

    return 0;
}