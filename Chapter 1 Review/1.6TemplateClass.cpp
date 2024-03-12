#include <iostream>

using namespace std;
// template <class T> // you can search about this template later on because this allows you to pass in any data types other than the ones that you defined already
class Arithmetic {

private:
    int a;
    int b;
public:
    Arithmetic (int a, int b);
    int add ();
    int sub();
};

Arithmetic :: Arithmetic (int a, int b){ // better to do this way where we define the function outside the class because it does form cluster structure inside our class
        this->a = a;
        this -> b = b; // as discussed in the c learning repo, the this pointer is basically a pointer that is used when the paramters are the same thing as the members of the class
    }
int Arithmetic::add () {
    return a + b;
}
int Arithmetic :: sub() {
    return a - b;
}
int main() {

    Arithmetic ar (10,20); // the constructor is called when i call the function with the same paramters as shown here

    cout << ar.add() << endl;

    cout << ar.sub() << endl;




    return 0;
}