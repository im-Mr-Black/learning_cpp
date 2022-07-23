#include <iostream>
using namespace std;

class A{
    public: 
    void fun(){

    }
};

class B{
    public:
        friend void fun();
}

void fun(){
    
};