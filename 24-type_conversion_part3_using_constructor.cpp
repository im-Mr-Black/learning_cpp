#include <iostream>
using namespace std;
class Product{
    int m, n;
    public:
        void setData(int a , int b){
            m = a;
            n = b;
        }
        void showData(){
            cout << "\na: " << m << " b: " << n;
        }
        int getM(){
            return m;
        }
        int getN(){
            return n;
        }
};
class Item{
    int a, b;
    public:
        void setData(int a , int b){
            this->a = a;
            this->b = b;
        }
        void showData(){
            cout << "\na: " << a << " b: " << b;
        }
        Item(Product p){
            a = p.getM();
            b = p.getN();
        }
        Item(){}
};


int main(){
    Item i1;
    Product p1;
    p1.setData(3,4);
    i1 = p1;
    i1.showData();
}