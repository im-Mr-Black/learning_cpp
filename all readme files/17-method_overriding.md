# Method Overriding

- method overloading
- method overriding
- method hiding

```cpp
#include <iostream>
using namespace std;

class A{
    public:
    void f1(){}
    void f2(int x){}
};
class B : public A{
    public:
    void f1(){}
    void f2(){}
};
```

toh agar class A aur class B, dono me same naam ka function banaya hai (`f1`) humne aur uske argument bhi same hai(notice class B is derived class of class A), toh ise hum method overriding bolte hai.

Jo function `f2` hai, woh dono class me same naam ka hai but farak yeh hai idhar ki dono me arguments ka difference hai, toh ise hum methoda hiding bolte hai.

```cpp
#include <iostream>
using namespace std;

class A{
    public:
    void f1(){}
    void f2(){}
};
class B : publics A{
    public:
    void f1(){}
    void f2(int x){}
};

int main(){
    B obj;
    obj.f1();   //idhar pe B class wala f1 chalega even though dono class me f1 naam ka function hai
    obj.f2();   // error
    obj.f2(5);  //child class, class B ka function se saath bind hoga yeh wala
}
```

Early binding hogi yaha pe, compiler ki yeh duty hai ki kaunsa `f1` chalega. Woh yeh dekhega aur phir uss function ko bind kar dega.

toh `obj.f1()` wala line hai uss part pe B class wala f1 chalega, even though dono class me `f1` naam ka ek function hai, toh usi class/scope ka function chalega.

now `obj.f2()`, `f2` iss baar bhi woh dono me hai also iss baar `f2` me koi argument bhi nahi hai, toh class A ka `f2` chalna chahie, hai na? But aisa nahi hoga, yeh error hoga even though parent function me waisa ek function hai jo iss condition ko satisfy kar raha hai. Agar yeh `f2` chal jaata class A ka toh ise hum **function overloading** kehte, toh iss case ko hum **function hiding** kehte hai.

> toh important note yeh hai ki 2 inter-related class(parent aur child) class me bhale hi same function ho, function wahi chalega jo uske scope me hai

Accha agar yahi `f2` function jo `int` argument le raha hai woh class B me bhi hota toh yeh overloading ho jaata. Toh idhar 2 concept clear hote hai ki kab overloading hoga aur kab overloading function ki nahi hogi.

> `obj.f2()` wale case me compiler pehle obj ke liye f2 function dhundega toh use woh class B me hi mil jaega, but phir waha woh yeh dekhega ki hamare wale f2 me koi argument nahi hai. isliye woh error dega. But agar yahi `f2` agar class B me nahi hota tab compiler class A me jaata `f2` ke liye phir class A wala f1 ke saath bind kar deta. Toh yeh hai woh case jab class A(parent class) ka function kisi child ke bane object se bind hoga.Hamare case me child class me use same naam ka function mil gaaya isliye woh parent class me search karne nahi gaya aur error de diya(very important thing to know)

## funtion overriding karna kab chahie

```cpp
#include <iostream>
using namespace std;

class Car{
    public:
    void shiftGear(){}
    void f2(){}
};
class SportsCar : public Car{
    public:
    //void f1(){}
    void f2(int x){}
};

int main(){
    SportsCar obj;
    obj.shiftGear();
}
```

toh iss case me hum yeh dekh rahe hai ki ek `Car` class hai aur uska ek sub class hai(`SportCar`), toh car me ek feature hai shift gear ka jo ki sports car me bhi hoga hi toh hame koi problem nahi hai plus yeh function hame ab wapas se `SportsCar` me nahi banana padega. So this code works perfectly fine until sports car me gear alag tareeke se shift ho rahe ho.

Toh iss case me agar hum alag naam ka function banaenge(for eg. gearChange) toh jab bhi `SportsCar` naam ka object banega woh 2 tareeke se gear change kar paega(using `shiftGear` and `gearChange`) but car me toh ek hi tareeke se gear change hoga toh, iss case me method overriding kaam aaegi.

> Toh basically parent aur child me same kaam alag alag tareeke se karne wale function ke case me method overriding ka use karte hai.

> Toh kabhi bhi parent class se mili kisi bhi service ko aap child class me badalna chahte hai toh aap overriding kariye.

```cpp
#include <iostream>
using namespace std;

class Car{
    public:
    void shiftGear(){}
    void f2(){}
};
class SportsCar : public Car{
    public:
    //void f1(){}
    void shiftGear(){}
    void f2(int x){}
};

int main(){
    SportsCar obj;
    obj.shiftGear();
}
```
