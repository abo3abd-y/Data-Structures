#include <iostream>

using namespace std;

int fib (int n) {
    if(n <= 1){
        return n;
    }else {
        return fib(n - 2) + fib(n - 1);
    }
}

// here we are using the fibbonacci series as a recursive function as you can see

// you will realize that the fibonacci function is calling itself multiple times for the same paramter

// that is why we have dynamic programming or memorization - the use of previous answers to answer the current problem

int fn[10];



int fib_ad (int n ) {
     if(n <= 1){
        fn[n] = n;
        return n;
    }else {
        if(fn[n - 2] == -1) 
            fn[n - 2] = fib_ad(n - 2);
        if(fn[n - 1] == -1)
            fn[n - 1] = fib_ad(n - 1);
        return fn[n-1] + fn[n - 2];
        
    }
}



int main() {
    for(int i = 0; i < 10 ; i ++ ){
        fn[i] = -1;
    }
    
    cout << fib(10) << endl << fib_ad(10) << endl; // works perfectly fine but the second function is better because it uses memorization
    return 0;
}