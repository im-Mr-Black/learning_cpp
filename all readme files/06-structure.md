# Structures

- structure is a collection of dissimilar elements.
- structure is a way to group variables.
- structure is used to create data types.
- array is group of variables just like structures, the only difference here is array will contain only one type of variables while structure can contain different types of variables.

## some important points about structures

- we can't directly access the members of the structures.

```cpp
#include <iostream>
using namespace std;

struct book{
    int bookid;
    char title[20];
    float price; //4 byte consume karta hai
};
// also this is a global datatype i.e. any one can use the datatype book
// till this point no memory has been used, since we are only defining the what is the content inside the structure book.
// we have defined a new datatype book.

book b2; // global variable

int main(){
    struct book2
    {
        /* this is locally defined datatype */
    };

    struct book b1; //local variable

    book b1 = {100, "Cpp", 54.0};
    book b2;
    b2.bookid = 101;  //this is how we can directly access the value inside the structure.

    //NOTE
    // remember you can't pass in string like b2.title = "Shubham", instead you need to use a function called strcpy, it is used to assign a string to a variable.

    strcpy(b2.title, "Shubham");
    b2.price = 300.0;
}
```

- let us assume that b2 and b3(new variable) has same data, then you can directly say b2=b3 instead of doing b2.title = b3.title and like that.

## taking user input

```cpp
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
```

## More about structures

(from part 4)

- encapsulation ka matlab se 1 entity se related jitni bhi properties hai un sab ka ek group banana chahie.

- `CPP` ke structure me hum functions bhi rakh sakte hai... while `C` ke structure me hum sirf variables hi store kar sakte hai.
- `CPP` ke structure me struct likhna mandatory nahi hai everytime you make a structure after its defined, while it is mandatory when using `C`.

```cpp
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
```

(from part 5)

- jaise ki book id kabhi bhi negative nahi ho sakti, yeh book ki policy ho sakti hai, so book id kabhi bhi negative na ho uske liye programmer input me changes karega taaki.

```cpp
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
```

- toh abhi tak humne yeh dekha ki Cpp ka data corrupt hone se kaise bachae, but abhi yeh data full proof nahi hai, koi again main me jaake `b1.bookid = -100` daal de toh woh input me chala jaega, C me iss pe koi solution exist nahi karta hai, toh CPP ne access specifier use karke hum iss problem se bach sakte( by not allowing anyone toh access structure ke andar ke variable in main). Access specifier 3 type ke hote hai, public private protected. Here we are going to use private.

```cpp
#include <iostream>
using namespace std;

void display();
struct book;
int input();

struct book
{
    private:  //changes
    int bookid;
    char title[20];
    float price;
    public:  //changes
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

//-- here is the change created --
int main(){
    book b1;
    b1.bookid = -100; //leading to an error as it is called private above
    b1.input();
    b1.display();

    return 0;
}
```

> **Important** OOPs ke kaafi important concept yeh hai ki kisi bhi variable ke member variables hai woh function ke through hi change hone chahie, isse data corrupt hone ke chances kam ho jaate hai.
