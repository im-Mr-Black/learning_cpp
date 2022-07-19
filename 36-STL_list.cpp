#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main(){
    list<int> l1(3,99);
    list<string> l2;
    list<int>::iterator p = l1.begin();
    while(p != l1.end()){
        cout << *p << " ";
        p++;
    }

    vector<int> v1{1, 2, 3};
    list<int> list1(v1.begin(), v1.end());
        auto pi = list1.begin();
    while(pi != list1.end()){
        cout << *pi << " ";
        pi++;
    }
    return 0;
}

