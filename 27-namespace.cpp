#include <iostream>
using namespace std;
namespace Myspace{
    int a;
    int f1();
    class A{
        public:
            void fun1();
    };
}

int Myspace::f1(){
    std::cout << "hello" << endl;
}
void Myspace::A::fun1(){
    cout << "hello fun1";
}

using namespace Myspace;
int main(){
    Myspace::a = 5;
    f1();
    A obj;
    obj.fun1();
}
