#include <iostream>
using namespace std;

class Complex{
    int a, b;

    public:
    void setData(int x , int y){
        a = x, b = y;
    }
    void showData(){
        cout << "\na: " << a << " b: " << b << endl;
    }
    friend Complex operator+(Complex, Complex);
};

Complex operator+(Complex c, Complex d){
    Complex temp;
    temp.a = d.a + c.a;
    temp.b = d.b + c.b;
    return temp;
};

int main(){
    Complex c1, c2, c3;
    c1.setData(3, 4);
    c2.setData(5, 6);
    c3 = c1 + c2;
    c3.showData();
}