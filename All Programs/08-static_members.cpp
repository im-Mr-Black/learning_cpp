#include <iostream>

// void fun(){
//     static int x;
//     int y;
// }

class Account
{
private:
    int balance; //instance member variable
    
    // declaring static member variable
    static float roi; //static member variable //class

public:
    void setBalance(int);
    static void setRoi(float);
};
float Account::roi = 3.5f; //declaring static member variable

void Account::setBalance(int b){
    balance = b;
}

void Account::setRoi(float r){
    roi = r;
}

void main(){
    Account a1;
    Account::setRoi(4.5f);
}