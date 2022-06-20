# Constructor

- Constructor is a member function of a class.
- the name of the constructor is same as the name of the class.
- it has no return type so you can't use return keyword inside the constructor.
- it must be an instance member function, that is, it can never be static.

### How to call a constructor

- Constructor is implicitly invoked when an object is created, yaani isme hum call nahi karte hai, yeh apne aap call hota hai, when an object is created.

```cpp
#include <iostream>

class Complex{
    private:
        int a, b;
        public:
        Complex()
        {
            std::cout << "Hello" << std::endl;
        }
};

int main(){
    Complex c1;
}
```

agar yeh 'hello' print hoga, iska matlab yeh hai constructor bana hai. `Complex c1;` yeh line ke run hote hi, constructor bana jaega aur yeh object banne ke baad create hota hai pehle nahi.

> agar mai 3 object banau for eg. `Complex c1,c2,c3;` toh isme constructor 1 baar chalega ki 3 baar chalega?.. iska answer hai 3 baar chalega kyuki yeh instance member function hai, iska matlab yeh teeno object ke liye alag alag banega.

- Constructor is used to solve problem of initialization.

## What is problem of initialization?

- why it is called constructor?

---

- what is the problem of initialization?

---

- How constructor resolves this issue?

---

### Constructor part 2

- default constructor
- parameterized constructor
- constructor overloading

ab hum chah rahe hai ki hum constructor me arguments bhi pass kar sake toh hum kaise karenge,

```cpp
#include <iostream>

class Complex{
    private:
        int a, b;
        public:
        Complex(int x , int y)
        {
            a = x;
            b = y;
        }
};

int main(){
    Complex c1(3,4);
}
```

toh agar hum bas `Complex c1;` likhte toh error ata kyuki complex class me aisa koi bhi constructor nahi hai jo argument nahi le raha ho, toh object aisa banana hoga jo argument leta ho. `Complex c1(3,4);` likhna sahi rahega taaki use yeh pata chal sake ki constructor me kya values daalni hai.

---

Now we want to pass only one value when we create an object.

```cpp
#include <iostream>

class Complex{
    private:
        int a, b;
        public:
        Complex(int x , int y)
        {
            a = x;
            b = y;
        }
        Complex(int z){
            a = z;
        }
        Complex(){
            a = 0;  b=0;
        }
};

int main(){
    Complex c1(3,4); //parameterized constructor
    Complex x2(4);   //parameterized constructor
    Complex x3;      //default constrcutor
}
```

So, this is more like function overloading, but here it is called **Constructor Overloading**.

accha `Complex c1(3,4)` ko ek aur tareeke se likh sakte hai hu i.e. `Complex c1 = Complex(3,4)`, dono me likna ka tareeka alag hai but meaning same hi hai.

> Object banega toh constructor call hoga hi hoga, bhale hi Class me koi constructor ho na ho but woh call zarur hoga, yaani jab aap class banate hai w/o constructor aur uske baad you create an object toh tab bhi constructor call hoga kyuki compiler ne hi ek constructor hamari taraf se bana diya hai(**default constructor** or **implicit default constructor**)

> accha agar aapne apne clas me agar constructor bana diya toh compiler ab default constructor nahi banaega.

- parameterized constructor - jo constructor arguments leta ho while creating an object.
- default constructor - jo constructor koi bhi values nahi leta ho while creating an object.

## Constructor part 3
