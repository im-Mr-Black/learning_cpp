# Virtual Function

- as we know ki pointer jis type ka hota hai usi type ke object ko point kar sakta hai, do alag alag class ke pointer apne apne class ke bane object ko point kar sakte hai. But jab unme inheritance aa jaata hai toh case thoda alag ho jaata hai.
- base class pointer can point to the object of any of its descendant(vanshaj) class, yaani pointer parent class ka hai toh woh apni child class ke object ko bhi point kar sakta hai. Bas yahi nahi woh apne se neeche(yaani child class, aur neeche matlab child ki bhi child class(descendant))ke koi bhi class ke object ko point kar sakta hai.
- But its converse is not true, yaani child class ka bana pointer parent class ke object ko point nahi kar sakta.

```cpp
#include <iostram>
using namespace std;

class A{
    public:
    void f1(){}
};

class B: public A{
    public:
    void f1(){} // method overriding
};

int main(){
    A *p, o1;
    B o2;
    p = &o2;
}
```

```cpp
#include <iostram>
using namespace std;

class A{
    public:
    void f1(){}
};

class B: public A{
    public:
    void f1(){} // function overriding
};

int main(){
    A *p, o1;
    B o2;
    p = &o2;
    o2.f1(); // B
    p->f1(); // A
}
```

idhar(`p = &o2;`) hum dekh sakte hai ki pointer `p` class A(Base class) ka hai aur woh class B(derived class) ke object ko point kar raha hai.

`o2.f1();` , jab hum aise call karte hai toh hame pata hai ki isme f1 child class(class B) ka chalega.But jab hum pointer ka use karte hai jo ki uss class ka na hoke parent class ka hota hai to again call this function `f1`(which is overridden by its child class) toh kahani different ho jaati hai.

Ab hum yeh jaante hai ki function ke call ko dekh kar uske sahi version ko bind karne ka kaam compiler karta hai aur use hum early binding kehte hai. Yaha pe bhi early binding hogi, toh jab hum `o2.f1();` call kiye toh toh class B ke `f1` se bind kar dega, but jab hum use pointer `p` se bulate(jo ki class A ka hai) uss time pe compiler ko yeh nahi pata ki pointer kise point kar raha hai(use yahi lagega ki woh apne hi class ke bane object ka address contain kar raha hai) isliye jab hum function `f1` call karenge woh class A ka `f1` ke saath bind kar dega. But yeh hume nahi chahie hume toh class B wala `f1` chahie.Yeh hai overriding ki problem, bas yahi ek problem hoti hai overriding ke waqt, hum chahte hai child class wala function chale.

**Solution**: Early binding na hone diya jae, balki late bind ho, toh aagar compile time pe hum function ko pointer ke saath nahi bind hone denge aur balki runtime pe bind karenge tab compiler ko yeh pata rahega ki pointer jo hai woh toh apne child class ke object ko point kar raha hai toh woh sahi se bind kar dega hamare function ko aur overriding phir se possible ho jaegi.Toh jab bhi hame kisi function ko compile time bind na karne ki jagah runtime pe bind karana hota hai uss function ko hum `virtual` keyword se tag karke compiler ko yeh bata dete hai ki uss function ko runtime pe bind karna hai.

Function overriding ke waqt hi hume virtual function banane ki zarurat padegi. Toh jab virtual function call hoga toh call ke waqt pointer ke type ko basis na rakh kar pointer ke content ke basis pe binding hogi.

```cpp
#include <iostram>
using namespace std;

class A{
    public:
    virtual void f1(){}
};

class B: public A{
    public:
    void f1(){} // function overriding
};

int main(){
    A *p, o1;
    B o2;
    p = &o2;
    o2.f1(); // B
    p->f1(); // A
}
```

toh ab jab humne `f1` function ko virtual ka tag de diya hai, ab wapas se child class me virtual keyword likhne ki koi zarurat nahi hai, woh apne aap virtual ho chuka hai, infact parent class ki descendant har class me agar `f1` hai toh woh ab virtual function hi hai.

hum kaafi saare virtual function bhi bana sakte hai usme bhi koi problem nahi hai.

### Virtual Function part 2

watch this [video](https://www.youtube.com/watch?v=Z_FiER8aAqM&list=PLLYz8uHU480j37APNXBdPz7YzAi4XlQUF&index=45) to understand the concept

```cpp
#include <iostream>
using namespace std;

class A{
    public:
    void f1(){}
    virtual void f2(){}
    virtual void f3(){}
    virtual void f4(){}
};

class B: public A{
    public:
    void f1(){}
    void f2(){}
    void f4(int x){}
}
```
