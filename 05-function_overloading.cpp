#include <iostream>
using namespace std;

int area(int x , int y){
    return (x * y);
}
float area(int r){
    return (3.14 * r * r);
}

int main(){
    int r;
    cout << "enter the radius of the circle: ";
    cin >> r;
    float A = area(r);
    cout << "\nArea of the circle is: " << A << endl;

    int l, b, a;
    cout << "Enter the value of length and breath of the rectangle: " << endl;
    cin >> l >> b;
    a = area(l, b);
    cout << "area of the rectangle is: " << a <<endl;
    return 0;
}