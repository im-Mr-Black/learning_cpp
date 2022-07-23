#include <iostream>
using namespace std;
class Complex
{
private:
    int a, b; //instance variable
public:
    void set_data(int , int);
    void show_data(int , int){
        cout << "\na" << a << " b" << b;
    }
    Complex add(Complex c){
        Complex temp;
        temp.a = a + c.a;
        temp.b = b + c.b;
        return (temp);
    }
};
// defining function outside the class complex
void Complex:: set_data(int x , int y){
    a = x;
    b = y;
}
int main(){
    Complex c1, c2 , c3;
    c1.set_data(3, 4);
    c2.set_data(5, 6);
    c3 = c1.add(c2);
    c3.show_data();
}


