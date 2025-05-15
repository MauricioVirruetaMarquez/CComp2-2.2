#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    Student st1;
    st1.print();

    Student st2("Mauricio", 19, 17391841);
    st2.print();

    return 0;
}
