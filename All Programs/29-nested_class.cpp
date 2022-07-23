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