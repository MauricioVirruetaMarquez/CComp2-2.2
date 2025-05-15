#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>

using namespace std;

class Student
{
    private:
        string name;
        int age;
        int code;
    public:
        Student(){
            cout<<"Invoncando al constructor de la clase"<<endl;
            name = "";
            age = 0;
            code = 0;
        }
        Student(string n, int a,int c){
            name = n;
            age = a;
            code = c;
        }
        ~Student(){
            cout<<"Invocando al destructor" <<endl;
        }
        void setName(string n) {
            name = n;
        }
        void setAge(int a) {
            age = a;
        }
        void setCode(int c) {
            code = c;
        }
        string getName() const {
            return name;
        }
        int getAge() const {
            return age;
        }
        int getCode() const {
            return code;
        }
        void print() const {
        cout<< name << endl;
        cout<< age << endl;
        cout<< code << endl;
        }


};

#endif // STUDENT_H
