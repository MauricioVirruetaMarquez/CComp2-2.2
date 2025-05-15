#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int age;
    int code;
    void print() const {
     cout<< name << endl;
     cout<< age << endl;
     cout<< code << endl;
    }

};

int main(){

Student st;
st.name = "Mauricio";
st.age = 19;
st.code = 1945;
st.print();

Student st2;
st2.name = "Sebastian";
st2.age = 21;
st2.code = 2012;
st2.print();

return 0;
}
