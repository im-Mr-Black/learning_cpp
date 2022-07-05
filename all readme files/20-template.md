# Template

- The keyword template is used to define function template and class template.
- It is a way to make your function or class generalize as far as data type is known.
- isko aise relate kar sakte hai jaise aap kisi college ka form bhar rahe hote ho toh aapko kuch details fill karni hoti hai taaki college ko aapki full knowledge ho aapke baare me, wahi sochie agar yeh form nahi hota toh koi zyada info de raha hota aur koi kam toh isse operations perform karne me dikkat aati. Toh yeh form ek template hai. Yeh ek generalize structure hai jise hum use karte hai aapne aapne kaam ke hisab se.

## Function Template

```cpp
#include <iostream>
using namespace std;

int big(int a , int b){
    if (a> b){
        return a;
    } else {
        return (b);
    }
}

int main(){
    cout << big(4, 5);
    cout << big(5.6, 3.4);
}
```

toh jab hum yeh function chala rahe hounge toh data loss hoga `big(5.6, 3.4);` ke case me 5, 3 jaega andar toh hum kya kar sakte hai. Hum functin overloading kar sakte hai for this not to happen.

```cpp
#include <iostream>
using namespace std;

int big(int a , int b){
    if (a> b){
        return a;
    } else {
        return (b);
    }
}
double big(double a , double b){
    if (a> b){
        return a;
    } else {
        return (b);
    }
}

int main(){
    cout << big(4, 5);
    cout << big(5.6, 3.4);
}
```

Toh humne function overloading karni padegi if we want to use both double as well as int type as our argument.

But, agar hume pata hai ki hum 2 arguments pass karenge aur hume unme se bada kaun hai bas yahi batana hai toh hum ek generalized function bana bhi toh sakte hai jo function ke argument type ko dekh kar apne aap dhal jaega. Toh ise hum template ka use karke bana sakte hai.

> Syntax `template <class type> type function_name(type arg1 , ...);`

```cpp
#include <iostream>
using namespace std;

template <class X> X big(X a , X b){
    if (a> b){
        return a;
    } else {
        return (b);
    }
}

int main(){
    cout << big(4, 5);
    cout << big(5.6, 3.4);
}
```

Toh hum template kaise banate hai, toh hum use karte hai `template` keyword, aur phir hum likhte hai class keyword angular brackets me aur use hum bolte hai place holder (here `<class X>`, X ki jagah hum kuch aur bhi naam de sakte hai that's up to you). Aur phir har data type ko hum uss `X` se replace kar dete hai, ab compiler function ki definition ko argument ke data type ke hisab se interpret karta rehta hai.
(`template <class X>` hum same line me bhi likh sakte hai aur class ke upar bhi likhe sakte hai, yaani function wali line me ho na ho koi farak nahi padta bas semi-colon(;) nahi lagana hai).

> hum ek se zyada type ke argument bhi use kar sakte hai, for example in above given code agar hum ek argument int type ka pass kare aur ek double type ka. Toh compiler toh confuse ho jaega, toh isse bachne ke liye hum 2 placeholder bana sakte hai. toh uska syntax hoga (for above case ):
>
> > `template <class X , class Y> X big(X a , Y b){//your code here}`

### template part 2

- template function is also called as generic function.

## Class Template

> Syntax:
>
> > `template <class type> class class_name{//write your code here};`

17.46
