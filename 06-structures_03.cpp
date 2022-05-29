#include <iostream>
using namespace std;

void display();
struct book;
int input();

struct book
{
    private:
    int bookid;
    char title[20];
    float price;
    public:
    void input(){
        cout << "Enter book id , title and price ";
        cin >> bookid >> title >> price;

        if (bookid < 0){
            bookid = -bookid;
        }
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