#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v3;
    for (int i = 1; i <= 9; i++){
        v3.push_back(i*10);
    }
    for (int i = 0; i < v3.size(); i++){
        cout << v3.at(i) << endl;
    }

    // here we are gonna use iterator
    vector<int>::iterator it = v3.begin();
    // if we wanna insert value between 20 and 30
    v3.insert(it + 2, 25);
    for (int i = 0; i < v3.size(); i++){
        cout << v3.at(i) << endl;
    }
}