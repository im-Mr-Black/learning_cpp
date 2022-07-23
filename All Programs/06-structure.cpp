#include <iostream>
using namespace std;

struct book
{
    int bookid;
    char title[20];
    float price;
};
void display(book);
book input();

int main(){
    book b1;
    b1 = input();
    display(b1);
}
void display(book b){
    cout << "book id , title and the price of the book is " <<b.bookid <<" " << b.title <<" " << b.price << endl;
}
book input(){
    book b1;
    cout << "Enter the book id , title and the price of the book" << endl;
    cin >> b1.bookid >> b1.title >> b1.price;
    return (b1);
}