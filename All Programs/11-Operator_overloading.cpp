#include <iostream>
using namespace std;

class Complex{
    private:
        int a, b;
    public:
    void setData(int x, int y){
        a = x;
        b = y;
    }
    void showData(){
        cout << "\na: " << a << " b: " << b;
    }
    Complex operator -(){
        Complex temp;
        temp.a = -a;
        temp.b = -b;
        return temp;
    }
};

int main(){
    Complex c1, c2, c3, c4;
    c1.setData(3, 4);
    c2.setData(5, 6);
    c3 = -c2;
    c4 = c1.operator-();
    c3.showData();
    c4.showData();
} 
