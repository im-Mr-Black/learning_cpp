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
        cout << "\na: " << a << " b: " << b << endl;
    }
};

int main(){
    Complex c1;
    cout << "Enter a complex number: ";
    cin >> c1;
    cout << 
}