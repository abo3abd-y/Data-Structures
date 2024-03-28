#include <iostream>

using namespace std;

// recursion functions are basically functions that call themselves inside their body code

// unlike traditinal functions, recursion function call themselves untill a cetain condition where the function stop calling itself

// example is shown below

void fun (int x){
    if(x > 0) {
        cout << "The integer is " << x << endl;
        fun(x - 1); // so we call the function again but with the same value as x minus 1
    }

    // the function should terminate when the function is 0 or any number less than that
    // without the above condition where x has to be greater than 0, the function will recursively call itself endlessly which is a very bad thing to happen


}

void another_fun (int x) {
    if(x > 0){
        another_fun(x - 1); // again the minus one is important because at the end of the day, the function terminates because x became 0 and nothing else
        cout << "The integer is " << x << endl;
    } // the difference in this fucntion from the previous one is that this function calls and then prints which means that the function will print numbers  in ascending order if you think about it
}

// so before the recursive call, the stuff that happen before the call is called calling because it happens during the function being called. this is also called ascending because it goes from to bottom unlike descending which is explained below

// but after the recursive call, the stuff that happen after the function call is called returning and is also called descending because it starts at the bottom

// finally, recursive functions are like loops except that they can possibly have both the ascending and descending phases


int main() {

    int x = 3;

    fun(x);
    another_fun(x);



    return 0;
}