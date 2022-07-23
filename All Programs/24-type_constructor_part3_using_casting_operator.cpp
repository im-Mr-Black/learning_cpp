#include <iostream>
using namespace std;
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
};

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
        operator Item(){
            Item temp;
            temp.setData(m, n);
            return temp;
        }
};
int main(){
    Item i1;
    Product p1;
    p1.setData(3,4);
    i1 = p1;
    i1.showData();
}