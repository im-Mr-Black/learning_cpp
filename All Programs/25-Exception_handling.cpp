#include <iostream>
using namespace std;

int main(){
    cout << "welcom" << endl;
    try
    {
        throw 10;
        cout << "\nIn try";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}