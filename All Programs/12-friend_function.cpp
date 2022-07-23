#include <iostream>
using namespace std;

class Complex{
    private:
        int a, b;
    public:
        void setData(int x , int y){
            a = x;
            b = y;
        }
        void showData(){
            cout << "\na: " << a << " b: " << b;
        }
        //declaring friend function
        void fun(Complex);
};

void fun(Complex c){
    cout << "\nSum is: " << c.a + c.b << endl;
}

int main(){
    Complex c1;
    fun()
}