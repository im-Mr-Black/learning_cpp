#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream fout;
    fout.open("myfile1.dat" , ios::app | ios::binary | ios::in);
    fout.close();
}