#include <iostream>

using namespace std;

class Diagonal {

    private:
        int n;
        int *a;
    
    public:
        Diagonal(int n) {
            this -> n = n;
            a = new int[n];
        }
        void set (int i, int j, int x);
        int get(int i, int j);
        void display();
        ~Diagonal() {delete []a;}


};

void Diagonal::set(int i, int j, int x) {
    if(i == j) {
        a[i - 1] = x;
    }
}
int Diagonal::get(int i, int j) {
    if(i == j) return a[i - 1];
    else return 0;
}
void Diagonal::display() {
    for(int i =0; i < n; i ++ ){
        for(int j = 0; j< n; j ++) {
            if(i == j) cout << a[i] << " ";
            else cout << "0" << " ";
        }
        cout << endl;
    }
}
int main () {

    Diagonal d(4);

    d.set(1,1,4);
    d.set(2,2,8);
    d.set(3,3,9);
    d.set(4,4,12);
    d.display();
    return 0;
}