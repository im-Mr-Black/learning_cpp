#include <iostream>

class Car{
    private:
        int gear;
    
    public:
    void incrementGear(){
        if(gear <5)
            gear++;
    }
};

class SportsCar : public Car{
    
}