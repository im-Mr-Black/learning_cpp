#include <iostream>
using namespace std;

class Box{
    int l, b, h;
    public:
        void setDimensions(int l , int b , int h){
            this->l = l;
            this->b = b;
            this->h = h;
        }
        void showDimensions(){
            cout << "\nlength: " << l << " breath: " << b << " height: " << h << endl;
        }
};

int main(){
    Box smallBox , *p;
    p = &smallBox;
    p->setDimensions(12, 10, 5);
    p->showDimensions();
}