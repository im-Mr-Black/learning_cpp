# Friend Function

- friend function is not a member function of a class to which it is a friend.
- friend function is declared in the class with friend keyword.
- it must be defined outside the class to which it is friend.

- friend function just like member function class ke kisi bhi member for access kar sakta hai but directly nahi kar sakta hai jaise member function kar sakte hai.
- friend function can't access members of the class directly.
- It has no caller object.
- It should not be defined with membership label

```cpp
#include <iostream>
using namespace std;

class Complex{
    private:
        int a, b;
    public:
        void setData(int x , int y){
            a = x;
            b = y;
        }
        void showData(){
            cout << "\na: " << a << " b: " << b;
        }
        //declaring friend function
        void fun();
};

void fun(){

}

int main(){

}
```

agar `void fun()` bas likha jae toh woh member function mana jaega, but agar `friend void fun()` likhenge toh toh woh friend function mana jaega.

Accha jab neeche define kar rahe hai toh 2 cheez notice karne layak hai ki humne na hi membership label lagaya hai aur na hi dubara `friend` keyword likha hai.

```cpp
void fun(){
    cout << "\nSum is: " << a + b << endl;
}
```

`fun` function ka definition jab ham likh rahe hai toh hum `a+b` aise hi nahi likh sakte, cause hum `a` aur `b` ko directly nahi access kar sakte hai. Reason- compiler ko yeh nahi pata chalega ki yeh `a` aur `b` kiske hai `c1` ke hai ki `c2` ke hai.

### Friend Funtion part 2

- Friend function can become friend to more that one class.

> well, hum friend function ko jab class me define karte hai toh, usse koi farak nahi padta ki hum private me define kar rahe hai ki public me kyuki woh class ka member hi nahi hail.

- accha hum jab friend function banate hai toh uska koi caller object hota hai nahi, toh hame argument me class ke variable ko pass kar dena sahi rehta hai, kyuki woh andar ke objects ko access nahi kar paega.

```cpp
#include <iostream>
using namespace std;

class A{
    int a;
    public:
        friend void fun(A , B);
};

class B{
    int b;
    friend void fun(A , B);
};

void fun(A o1 , B o2){
    cout << "sum is: " << o1.a + o2.b;
}

int main(){

}
```

- (look in the definition of friend function) yaha pe aap yeh clearly dekh sakte hai ki yeh function ek baar me ek hi time pe 1 class ke member ko access kar paa raha hai, plus unpe operations bhi perform kar paa raha hai, toh yeh sirf friend function hi kar sakta hai.

### friend function part 3

- jab bhi hum kisi binary operator ko overload karte hai toh hum toh hum bas ek hi argument pass karte hai jab hum as a member function call karte hai, but jab hum use as a friend function call karte hai tab koi caller object hota hi nahi hai, isliye hum dono objects ko argument me pass karte hai.

```cpp
#include <iostream>
using namespace std;

class Complex{
    int a, b;

    public:
    void setData(int x , int y){
        a = x, b = y;
    }
    void showData(){
        cout << "\na: " << a << " b: " << b << endl;
    }
    friend Complex operator+(Complex, Complex);
};

Complex operator+(Complex c, Complex d){
    Complex temp;
    temp.a = d.a + c.a;
    temp.b = d.b + c.b;
    return temp;
};

int main(){
    Complex c1, c2, c3;
    c1.setData(3, 4);
    c2.setData(5, 6);
    c3 = c1 + c2;
    c3.showData();
}
```

`c3 = c1 + c2;` ise hum pehle aise read karte the `c1.operator+(c2)` but ab yeh friend function hai toh hum ise ab `operator+(c1, c2)` aise read karenge.

- general definiton - jab hum member function banate the, binary ho unary ho ya koi aur, jitte bhi argument hote the jab hum as a member function banate the, usse ek zyada argument lagega uss function ke liye jab hum use as a friend function banaenge.

### friend function part 4

```cpp
#include <iostream>
using namespace std;

class Complex{
    int a, b;

    public:
    void setData(int x , int y){
        a = x, b = y;
    }
    void showData(){
        cout << "\na: " << a << " b: " << b << endl;
    }
    friend Complex operator-(Complex);
};

Complex operator-(Complex c){
    Complex temp;
    temp.x = -c.x;
    temp.y = -c.y;
    return temp;
}


int main(){
    Complex c1, c2;
    c1.setData(3, 4);
    c2 = -c1;  // c2 = operator-(c1)
    c2.showData();
}
```

abhi humne yeh dekha ki unary operator ki overloading using friend function kaise karte hai.

### friend function part 5

`cin.operator>>(c1)` is same as `cin>>c1`

```cpp
#include <iostream>
using namespace std;

class Complex{
    private:
        int a, b;

    public:
    void setData(int x , int y){
        a = x;
        b = y;
    }
    void showData(){
        cout << "\na: " << a << " b: " << b << endl;
    }
    friend Complex o
};

int main(){
    Complex c1;
    cout << "Enter a complex number: ";
    cin >> c1;
    cout <<
}
```

toh for now if we focus on `cin >> c1;`, this will lead to an error, kyuki `cin` ko yeh nahi pata ki complex value ko kaise lete hai, woh sirf int, float, char le sakta hai.

So agar hame `cin` me complex value daalni hai toh hame iss operator ki overloading karna padega.

---

### friend function part 6

- toh agar tumhe kisi function ko as a friend call karna hai aur woh function kisi dusre class me exist karta hai toh, tum `friend void A::fun();` karke call kar sakte ho
- notice humne scope resolution ka use kiya hai taaki hum compiler ko bata sakte ki yeh function friend kaha se liya hua hai
- also, agar aisa scene hai ki kisi ek class me 5-10 function hai and you want to friend them all into some other class then you can also call a class as a friend, that way you don't have to call every function as a friend, but agar let's say there are 10 functions in class A and you want to friend 9 functions from class A then you have to call friend function for every single function .`friend class A;` aise likh ke you can friend the whole class.

```cpp
#include <iostream>
using namespace std;

class A{
    public:
    void fun(){

    }
};

class B{
    public:
        friend void fun();
        friend class A;
}

void fun(){

};
```
