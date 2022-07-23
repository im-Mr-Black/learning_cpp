#include <iostream>
#include <set> 
using namespace std;

class Student{
    private:
        int age;
        string name;
    public:
        void setStudent(string s , int a){
            name = s;
            age = a;
        }
        int showStudent(){
            cout << "\nName: " << name;
            cout << "\nAge: " << age;
        }
};

int main(){
    pair<string, int> p1;
    pair<string, string> p2;
    pair<string, float> p3;
    pair<int, Student> p4;

    p1 = make_pair("Rahul" , 16);
    p2 = make_pair("India", "new delhi");
    p3 = make_pair("drilling cpp", 345.5f);
    Student s1;
    s1.setStudent("aishwarya", 19);
    p4 = make_pair(1, s1);

    //accessing pair member
    cout << "\nPair 1: " << p1.first << " " << p1.second << endl;
    cout << "\nPair 2: " << p2.first << " " << p2.second << endl;
    cout << "\nPair 3: " << p3.first << " " << p3.second << endl;
    Student s2 = p4.second;
    cout << "\nPair 4: " << p4.first << " " ;
    s2.showStudent();
}