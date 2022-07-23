#include <iostream>
using namespace std;

class A{
    int a;
};
class B: public A{
    int b;
};
int fun(){
    A *p = new B;
}

int main(){
    fun();
}