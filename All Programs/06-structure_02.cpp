#include <iostream>
using namespace std;

void display();
struct book;
int input();

struct book
{
    int bookid;
    char title[20];
    float price;
    void input(){
        cout << "Enter book id , title and price ";
        cin >> bookid >> title >> price;
    }

    void display(){
        cout <<"\n" << bookid <<" "<< title <<" " << price << endl;
    }
};


int main(){
    book b1;
    b1.input();
    b1.display();

    return 0;
}