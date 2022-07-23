#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, string> customer;
    customer[100] = "gajendra";
    customer[123] = "dilip";
    customer[145] = "aditya";
    customer[171] = "shahid";
    customer[200] = "rajesh";

    customer.insert(pair<int, string> (205, "Shubham"));
}