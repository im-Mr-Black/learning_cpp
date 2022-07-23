#include <iostream>
using namespace std;
class integer{
    private:
        int x;

    public:
        void setData(int);
        void showData();
        integer operator++();
        integer operator++(int);
};

void integer::setData(int a){
    x = a;
};
void integer::showData(){
    cout << "x: " << x << endl;
};
integer integer::operator++(){
    integer i;
    i.x = ++x;
    return i;
};
integer integer::operator++(int){
    integer i;
    i.x = x++;
    return i;
};

int main(){
    integer i1 ,i2;
    i1.setData(3);
    i1.showData();
    i2 = ++i1;
    i1.showData();
    i2.showData();
    i2 = i1++;
    i1.showData();
    i2.showData();
}