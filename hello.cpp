#include <bits/stdc++.h>
using namespace std;
struct Trio {
    int x;
    int y;
    int z;
};
void fun() {
    map<Trio, int> hash;
    Trio t1;
    t1.x = 0;
    t1.y = 1;
    t1.z = 2;
    hash[t1] = 10;
    for(auto i: hash) {
        Trio temp = i.first;
        cout << i.second << temp.x << temp.z << endl;
    }
}
int main()
{
    fun();
    return 0;
}