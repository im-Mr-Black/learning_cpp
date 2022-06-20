# Destructor

- it is an instance member function of a class.
- the name of the destrucor is same as the name of a class but preceded by tilde(~) symbol.
- Destructor can never be static.
- it has no return type either.
- it takes no argument(no overloading is possible).

```cpp
#include <iostream>

class complex{
    private:
        int a, b;
        public:
        ~Complex(){
            //empty destructor
        }
};
```

- toh aap destructor me argument nahi pass kar sakte, iska matlab uska sirf ek hi version exist karega, that implies isme function overloading bhi nahi hogi.
  Compiler khud bhi ek destructor banata hai, agar aap nahi banaenge, aur agar aap bana denge toh compiler nahi banaega.
- Compiler empty body wala destructor banata hai.
- Constructor apne aap call hota hai, aur yeh tab call hota hai jab object destroy hone wala hota hai.

> Destructor object ko destroy karta hai, jee nahi woh object ki life chalne wala aakhri function hota hai, iska matlab jaise object kisi function ke andar bana hai, toh woh function ke khatam hote hi destroy ho jaega but woh destructor ki wajah se nahi hoga. Toh jaise hi object destroy hone wala hoga usse just pehle yeh destructor ki coding chal jaegi.

- it is invoked implicitly when object is going to destroy.

- **use of destructor** toh destructor me hum woh kaam ya coding karte hai jo hum object ke destroy hone ke baad nahi kar paenge, jaise hum kisi object ne jo resources use kiye hai woh bhi release kar de kyuki object ke destroy hote hi uske saath uska pointer bhi chala jaega jo uss resource ko point kar raha hoga.

agar hum object ko destroy kar de bina resource ko destroy kiye toh woh object toh chala jaega aur hum woh resource ko use bhi nahi kar paenge plus woh extra space bhi consume kar lega.

> its not important to create a destructor every time you create a class, it is just to clear the memory used by the resources it uses.
