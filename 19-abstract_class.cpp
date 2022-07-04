#include <iostream>
using namespace std;

class Person{
    public:
        virtual void fun() = 0;
        void f1(){}
};
class Student : public Person{
    public:
        void fun(){}
};
int main(){
    Student s1;
}