# Constructor and Destructor in Inheritance

## Constructor in Inheritance

- so we know that constructor is invoked implicitly when an object is created.
- In inheritance, when we create an object of derived class, **what will happen?**
  > toh tab constructor banega dono hi class ke liye derived aur parent class ke liye.

> Inheritance ke case me constructor ke chalne ka order hota hai from parent to child. For eg. if we create 2 class, class A and class B, aur class B is derived class of class A, now when we create a object of class B then constructor banega B ka but woh class A ke constructor ko call karega toh pehle woh run hoga phir class B ka constructor run hoga. Ek aur baar for more clearity, `B():A()` aisa ek constructor banega class B me jab class B ka ek object create hoga(yeh yaa toh hum banaenge aur agar hum nahi banaenge toh compiler bana dega), toh agar isme dhyaan se dekhe toh pehle class B ka constructor call hoga phir class A ka constructor call hoga(yaani wahi baat class B ka constructor class A ke constructor ko call karege), now class A ka constructor call hone ke baad woh run bhi hoga aur class A ka constructor jab run ho jaega phir uske baad class B ka constructor run hoga.

```cpp
#include <iostream>
using namespace std;

class A{
    private:
        int a;
    public:
        A(int k){
            k = a;
        }
};
class B:public A{
    private:
        int b;
    public:
        B(int x , int y):A(x){
            y = b;
        }
};

int main(){
    B obj(2, 3);
    return 0;
}
```

now upar wala code kaafi interesting hai, toh isme aisa kya hai jo ise interesting banata hai.

Toh baat yeh hai ki jab aap class A me constructor banate ho but class B me nahi banate, toh iss case me kya hoga, compiler class B ka default constructor banaega, but jab woh yeh bana raha hoga woh class A ke constructor ko bhi call karega, now compiler ko nahi pata ki humne waha pe ek constructor define karke rakha hua hai jise arguments ki garaj hai, woh kya karega class A ke default constructor ko call karega aur woh toh exist hi nahi karta. Toh yaha aaegi error, toh ab kya kare, toh **jab bhi parent class me constructor exist karta hai toh uske child class me bhi constructor banana zaruri hai**.

ab upar wala code dekhte hai, toh parent class hai `class A` aur `class B` uski derived class hai. Ab jo `class A` ka constructor hai use me ek argument lagti hai use call karne ke liye toh jab `main` function me humne `class B` ka object banaya toh `class B` ka constructor banega woh `class A` ke constructor ko call karega, toh jab woh call kar raha hoga toh use ek argument bhi chahie hoga call karne ko, toh woh hame `class B` ke constructor ki coding ke waqt karna padega.Now, iss case me hum yeh chah rahe hai ki `class B` ka constructor 2 arguments le jab woh object create kar raha ho, usme se ek woh `class B` ke variable `y` ko pass kar dega aur ek `class A` ke `x` ko pass kar dega(But wait! woh aise toh nahi kar paega `class A` ke `x` ko value pass(private member), toh hum `class A` ke constructor ko call karenge jo `class A` ke variable `x` me value set kar dega, simple!).

# Destructor in Inheritance

Toh destructor hum banate hai object ki memory ko release karne ke liye, jo object ke khatam hone se just pehle ho jaani chahie.

Ab, jab class B ka object destroy hone wala hoga usse just pehle class B apna destructor chala lega phir class A apna destructor chala lega(constructor ke case me ulta tha, yaad rakhna). Toh call ka order toh dono me hi same hai, pehle child ka call hua phir parent ka, but execution ka order dono ka ulta hai, idhar pehle child phir parent.

kyuki destructor ko koi argument ki garaj nahi hai toh agar aap destructor nahi bhi banate toh koi compiler apne ek destructor bana lega. Toh agar aapne class B ka destructor banaya hai aur usme class A ke constructor ko call karne wali zaruri step nahi likhi hai toh compiler khud hi woh step likh lega.

```cpp
#include <iostream>
using namespace std;

class A{
    private:
        int a;
    public:
        A(int k){
            k = a;
        }
        ~A(){}
};
class B:public A{
    private:
        int b;
    public:
        B(int x , int y):A(x){
            y = b;
        }
        ~B(){}
};

int main(){
    B obj(2, 3);
    return 0;
}
```
