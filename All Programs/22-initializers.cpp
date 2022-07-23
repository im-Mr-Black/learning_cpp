#include <iostream>
using namespace std;

class Dummy{
    private:
        int a , b;
        const int x;
        int &y;

    public:
    Dummy(int n):x(5), y(n){
    }
};

void fun(){
    const int y = 5;
}

int main(){
    int m = 6;
    Dummy obj(m);
}