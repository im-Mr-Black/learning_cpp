#include <iostream>

class Complex{
    private:
        int a, b;
        public:
        ~Complex(){
            std::cout << "destructor";
        }
};

void fun(){
    Complex obj;
}

int main(){
    fun();
}