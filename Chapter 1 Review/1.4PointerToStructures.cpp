#include <iostream>

using namespace std;

struct Rect {
    int length;

    int width;


};

int main() {
    Rect r = {10,20};

    Rect *p = &r;

    r.length = 15;

    p -> width = 200; // a pointer can access the member of the thing that it is pointing to by using the pointer notation

    // or it can use the following
    
    (*p).length = 2;


    cout << r.width << endl << r.length << endl;

    // so there are two ways a pointer can access the members of the thing that it is pointing to

    Rect *another_p;

    another_p = new Rect[3];

    // as you can see, we have stored three rect structures in the new pointer but we stored it in the heap

    another_p[0].length = 10; // we just use the list notation to access the rectangle and then the normal notation to access the member of that rectangle

    cout << another_p[0].length << endl;

    

    return 0;
}