#include <iostream>
using namespace std;

class A{
    private:
        int a, b;
        int *p;

    public:
    A(){
        a = 0;
        b = 0;
    }
    A(int x , int y){
        a = x;
        b = y;
        p = new int;
        *p = z;
    }
};

int main(){
    A(int x, int y, int z){
        a = x;
        b = y;
    }
}
