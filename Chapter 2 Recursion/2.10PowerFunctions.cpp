#include <iostream>

using namespace std;

int pow(int m, int n) {
    if (n == 0) {
        return 1;
    }else{
        return pow(m, n - 1) * m;
    }
}

int main() {

    cout << pow(2,3) << endl; // as you can see, this works perfectly with the recursion even though we could have done this using the ^ notation instead of doing a recursion function

    

    return 0;
}