# Nested Class

- class inside a class is called nested class.
- a nested class is a member and as such has the same access rights as any other member.
- the members of any enclosing class have no special access to members of a nested class; the usual access rules shall be obeyed.

```cpp
#include <iostream>
#include <string.h>
using namespace std;

class Student{
    private:
        int rollno;
        char name[20];
        class Address{
            private:
                int houseno;
                char street[20];
                char city[20];
                char state[20];
                char pincode[7];
            public:
            void setAddress(int h, char *s , char *c , char *st , char *p){
                houseno = h;
                strcpy(street, s);
                strcpy(city, c);
                strcpy(state, st);
                strcpy(pincode, p);
            }
            void showAddress(){
                cout << "Address: " << houseno << ", " << city << ", " << state << "- " << pincode << endl;
            }
        };
        Address add;
    public:
        void setRollno(int r){
            rollno = r;
        }
        void setName(char *n){
            strcpy(name, n);
        }
        void setAddress(int h , char *s , char *c , char *st , char *p){
            add.setAddress(h, s, c, st, p);
        }
        void showStudent(){
            cout << "Student Data: " << endl;
            cout << "Roll Number: " << rollno << endl;
            cout << "name: " << name << endl;
            add.showAddress();
        }
};

int main(){
    Student s1;
    s1.setRollno(100);
    s1.setName("rahul");
    s1.setAddress(254, "Q block", "Vellore", "Tamil Nadu", "632014");
    s1.showStudent();
}
```

Toh aise banta hai nested class, toh abhi hum dekh rahe hai ki humne jo nested class hai woh private me define kiya hua hai aur phir humne usme private members aur public members banae hue hai. Toh yeh baat dhyaan rakhni hai ki bhale hi `Address` class `Student` class ke andar hai, woh phir bhi uske private members ko access nahi kar sakta hai, plus agar hume unn members ko access karna hi hai toh hume unn members ke liye ek function banana padega public me jisse hum data input/output kar sake. Aur ek baat hum `Address` class ka object main me nahi bana sakte kyuki uska koi vajud nahi hai bina `Student` class ke.

Ab agar humne yahi `Address` class public me banai hoti toh hum toh iske bane object ko kaise access karte? toh agar humne aisa kiya hota toh hum address class ka object bhi bana pate plus use access bhi kar pate but yeh sab hum directly nahi kar paate hume scope resolution operator ka use karna padta aisa karne ke liye.

```cpp
int main(){
    //to make object of address class
    Student::Address a1;
    //to use all its function, isme no changes
    a1.showAddress();
}
```

Toh humne yeh bhi dekha ki access modifier bhi important role play karti hai, agar class private me hai toh kya hoga aur agar public me hoga toh kya hoga.

For more detailed info [watch video](https://www.youtube.com/watch?v=WE01T8okZTA&list=PLLYz8uHU480j37APNXBdPz7YzAi4XlQUF&index=64&t=416s).
