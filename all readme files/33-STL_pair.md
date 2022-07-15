# Pair

- pair is a template class in standard template library.
- pair is not a part of container.

## Syntax of using a pair object

`pair <T1, T2> pair1;`

example:

```cpp
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
        void showStudent(){
            cout << "\nName: " << name;
            cout << "\nAge: " << age;
        }
};

int main(){
    pair<string, int> p1;
    pair<string, string> p2;
    pair<string, float> p3;
    pair<int, Student> p4;
}
```

so this is how you can make pair of any two objects.

## Inserting values in pair

`p1= make_pair("ram" , 16);` this is how we can make pair(using make_pair function)

```cpp
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
        void showStudent(){
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
}
```

This is how we have made pair of every single data type we had.

## Accessing pair members

```cpp
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
```

so this is how we can access pair members, but there is a catch when a member is a class object. You have to store that object in some class object and then use the function(like `showStudent` used here) to show the data in the class object.

Class ke object ko hum directly show nahi kar paenge.

## Use of comparision operator

So, we can use comparision operator to compare the two objects in the pair.

- `==`
- `!= `
- `< `
- `>`
- `<=`
- `>=`
