#include <iostream>
using namespace std;

class Complex
{
private:
    int a, b;

public:
    void set_data(int , int);
    void show_data(int , int){
        cout << "\na" << a << " b" << b;
    }
};
// defining function outside the class complex
void Complex:: set_data(int x , int y){
    a = x;
    b = y;
}

int main(){
    Complex c1;
    c1.set_data(3, 4);
    c1.show_data();
}