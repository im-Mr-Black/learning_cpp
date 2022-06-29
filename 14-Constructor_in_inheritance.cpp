#include <iostream>
using namespace std;

class A{
    private:
        int a;
    public:
        A(int k){
            k = a;
        }
        ~A(){}
};
class B:public A{
    private:
        int b;
    public:
        B(int x , int y):A(x){
            y = b;
        }
        ~B(){}
};

int main(){
    B obj(2, 3);
    return 0;
}