#include <iostream>
using namespace std;

class Car{
    public: 
    void shiftGear(){}
    void f2(){}
};
class SportsCar : public Car{
    public:
    //void f1(){}
    void shiftGear(){}
    void f2(int x){}
};

int main(){
    SportsCar obj;
    obj.shiftGear(); 
}