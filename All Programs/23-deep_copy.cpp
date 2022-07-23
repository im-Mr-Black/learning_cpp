#include <iostream>
using namespace std;

class Dummy{
    private :
        int a, b;
    public:
    void setData(int x , int y){
        a = x;
        b = y;
    }
    void showData(){
        cout << "\na = " << a << " b= " << b << endl;
    }
    Dummy(Dummy &d){
        a = d.a;
        b = d.b;
    }
};

int main(){
    Dummy d1;
    d1.setData(3, 4);
    Dummy d2 = d1;
    d2.showData();
}