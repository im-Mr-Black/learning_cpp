#include <iostream>
using namespace std;

class B;  // forward declaration
class A{
    int a;
    public:
        friend void fun(A , B);
};

class B{
    int b;
    friend void fun(A , B);
};

void fun(A o1 , B o2){
    cout << "sum is: " << o1.a + o2.b;
}

int main(){
    A a1;
    B a2;
    fun(a1, a2);
} 