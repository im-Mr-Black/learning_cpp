#include <conio.h>
#include <iostream>
using namespace std;

int add(int, int=0);

int main(){
    int a, b;
    cout << "Enter the values of a and b" << endl;
    cin >> a >> b;
    cout << add(a, b);
}
int add(int a,int b){
    return (a + b);
}