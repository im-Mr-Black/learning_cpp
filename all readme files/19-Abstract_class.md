# Abstract Class

## pure virtual function

- a do nothing function is called pure virtual function.

```cpp
#include <iostream>
using namespace std;

class Person{
    public:
    void fun() = 0; //do nothing function
}
```

iska matlab hai `void fun() = 0;` ek do nothing function hai, yaani iski defintion na hi andar likhi gai hai na hi bahar(scope resolution laga ke).

Agar hum `void fun() = 0;` ki jagah `void fun();` yeh bas likhte toh compiler yeh maanta ki `fun` function ki definition shayad class ke bahar scope resolution laga ke ki gai hai, but hume toh na hi bahar aur na hi andar define karna tha isliye use hum zero se equate kar diya taaki compiler ko pata chal sake yeh do nothing function hai.

Accha agar hum `person` class ka object bana ke agar `fun` function ko call kare toh woh error hona chahie kyuki woh toh exist hi nahi karta. Toh CPP me ek rule banaya gaya ki **agar kisi class me do nothing function exist karta hai toh hum uss class ka object bana hi nahi sakte**.

But hum uss class ki child class zarur bana sakte hai, but fir hum `fun` function bhi inherit kar lenge aur phir hum use call bhi kar sakte hai, toh again yeh error dega. Toh ek aur rule banaya gaya CPP me ki **agar kisi aisi class jisme do nothing function exist karta hai uska child class banaya jaata hai toh hume uss do nothing function ki overriding karna zaruri hai**.

```cpp
#include <iostream>
using namespace std;

class Person{
    public:
        void fun() = 0;
        void f1(){}
};
class Student : public Person{
    public:
        void fun(){}
};
int main(){
    Student s1;
}
```

## agar hume `person` class me pade `f1` function ka use karna hai toh hume uski child class banani hi padegi, aur `fun` function ki overriding bhi karni padegi.

Abhi bhi ek tareeka hai jisse `fun` function call ho sakta hai, aur woh yeh hai ki agar hum ek pointer banae `Person` class ka aur woh point kar `Student` class ke object ko toh, tab bhi hum `fun` function ko call kar sakte hai. Toh isse bachne ke liye hume `fun` function ko virtual tag laga ke uski late binding karani padegi taaki compiler early bind karne ke chakkar me do nothing wale fun function ke saath bind na kar de.

```cpp
#include <iostream>
using namespace std;

class Person{
    public:
        virtual void fun() = 0;  //pure virtual function
        void f1(){}
};
class Student : public Person{
    public:
        void fun(){}
};
int main(){
    Student s1;
}
```

Ab isse kya hoga, `fun` function ki late binding hogi aur woh uss basis pe hogi ki pointer kise point kar raha hai naa ki pointer kis type ka hai.

> toh `Person` class ka `fun` function pure virtual function kehlata hai aur jiss class me pure virtual function exist karta hai uss class ko hum **Abstract class** bolte hai.

---

## Why do we make abstract class or why do we make pure virtual function?

iss concept ka use generalization ke liye hota hai.
![Why abstract Class?](/all%20readme%20files/images/why%20abstract%20class.png)

For example, upar wali image me dekhe toh agar yeh ek college ka database hai jaha student class hai aur ek faculty class hai, toh unn dono me kuch general baatein hongi jo common hongi like sabka naam , mobile number , address like that toh woh ek baar student me likhe aur phirse faculty me yahi likhe usse accha ek general class bana di person naam ki jo yeh sab common properties contain karegi but hume person naam ka na hi object banana hai na hi hume interest hai kyuki agar object ban bhi gaya toh hum yeh toh define hi nahi kar sakte ki woh person student hai ki faculty. Toh hum Person class ko as Abstract class bana dete hai, taaki uska koi object koi create na kar sake.

aur hum child class pe dabav bana sakte hai ki parent class me pade virtual function ko child me define karna padega. Toh hum aisa koi ek function bana sakte hai jiski definition student me alag ho aur faculty me alag aur uska koi matlab hi naa ho person class me.
