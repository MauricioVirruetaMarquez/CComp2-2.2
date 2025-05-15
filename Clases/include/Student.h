#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student
{
    private:
        string name;
        int age;
        int code;
    public:
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


};

#endif // STUDENT_H
