#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    Student st;
    st.setName("Mauricio");
    st.setAge(19);
    st.setCode(1945);

    cout<<st.getName()<<endl;
    cout<<st.getAge()<<endl;
    cout<<st.getCode()<<endl;

    return 0;
}
