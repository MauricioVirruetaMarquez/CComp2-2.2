#include <iostream>

using namespace std;


int main(){

    int *ptr;

    int val = 30;

    cout<< val << endl;
    cout<< &val << endl;

    ptr = &val;

    cout<< ptr<< endl;
    cout<<*ptr<< endl;
    *ptr = 1000;

    cout<< val << endl;

    int *ptr2 = &val;
    *ptr2 = 500;
    cout << *ptr2 << endl;

    double d = 20.5;
    double *ptr3 = &d;
    cout << *ptr3 << endl;

    char car = 'A';
    char *ptr4 = &car;
    cout<< *ptr4 << endl;

    return 0;

}
