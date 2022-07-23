#include <iostream>
#include <tuple>
using namespace std;

int main(){
    // creating a tuple
    tuple<string, int, int> t1;

    // inserting values in tuple
    t1 = make_tuple("shubham", 35, 125);

    // accessing values in a tuple
    cout << get<2>(t1);
}