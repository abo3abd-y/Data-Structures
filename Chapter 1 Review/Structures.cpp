#include <iostream>
#include <string>

using namespace std;

struct Rectangle { // this is how we are supposed to create structures. Remember by default, the members of a struct is a public
    int length;

    int width;

};

struct studentInfo { // you can calculate the number of bytes this struct is taking by adding up all the bytes those members are taking
    int studentID;
    string studentName;
    string school;
    string address;

};

int main () {
    
    Rectangle a; // this is how we are supposed to create structs in c++
    Rectangle b = {10,20}; // this is how we declare and initialize values in c++
    studentInfo abdullah;

    abdullah.studentID = 111111;
    abdullah.studentName = "Abdullah Yassine";
    abdullah.school = "School of Engineering";
    abdullah.address = "Whatever it is";


    a.length = 10; // this is how we are supposed to assign the members of an object to some values
    a.width = 20;

    cout << a.length << endl; // this is how we can access them 

    cout << a.width << endl;

    cout << b.length << endl;

    cout << b.width << endl;

    studentInfo studentTotal[3] = {{432432, "omar", "engineering", "9032 s lepton st"}, {8395732, "john", "medicine", "9282 n mcnickelton st"}}; // you can also create a list of structs just like creating a list of integers


    cout <<  studentTotal[0].studentName << endl;  //this is how you can access the members of a struct that is in a list


    return 0;
}