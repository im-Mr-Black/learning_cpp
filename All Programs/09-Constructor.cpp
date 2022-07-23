#include <iostream>

class Complex{
    private:
        int a, b;
        public:
        Complex(int x , int y)
        {
            a = x;
            b = y;
        }
        Complex(int z){
            a = z;
        }
};

int main(){
    Complex c1(3,4);
}