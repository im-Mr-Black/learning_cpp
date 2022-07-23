#include <iostream>
using namespace std;

class A{
    public:
    virtual void f1(){}
};

class B: public A{
    public:
    void f1(){} // function overriding
};

int main(){
    A *p, o1;
    B o2;
    p = &o2;
    o2.f1(); // B
    p->f1(); // A
}