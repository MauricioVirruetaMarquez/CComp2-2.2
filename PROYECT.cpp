#include <iostream>

using namespace std;

int* f() {
    int x = 10;
    return &x;
}
int* f2()
 {
     int *p = new int;
     *p = 5000;
     return p;
 }
int main()
{
    int *ptr;
    if(true) {
        int x = 10;
        ptr = &x;
    }
    cout << *ptr << endl;
    //int *ptr2 = f();

    //cout << *ptr2 << endl;

    int *ptr3 = new int;
    *ptr3=100;
    cout << *ptr3 << endl;
    delete ptr3;

    int *ptr4 = f2();
    cout << *ptr4 << endl;
    delete ptr4;



    return 0;
}
