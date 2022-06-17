# Static Members

## Static local variable

- They are by default initialized to zero.
- their lifetime is throughout the program.

```cpp
#include <iostream>

void fun(){
    static int x;
    int y;
}
```

about `x` - toh iski yeh khaas baat hoti hai ki iski by default value zero hoti hai, koi garbage value nahi hoti hai. iss variable ki lifetime throughout the program hai
about `y` - yeh variable static variable nahi hai.
difference between `x` and `y`, toh jab fun function ko call kiya jaega tab `y` variable ko memory milegi but `x` variable ko program start hote hi memory milegi.
`x` ki memory tab tak destroy nahi hogi jab tak program end nahi hoga but `y` ki memory function khatam hote hi khatam ho jaegi.
`y` baar baar banega aur baar baar destroy hoga, jabki `x` ki ek hi copy exist karegi aur wahi saari jagah chalegi.

## Static member variable

- declared inside the class body
- also known as class member variable
- it must be defined outside the class
- static member variable does not belong to any object, but to the whole class.
- there will exist only one copy of static member variable for the whole class.

```cpp
#include <iostream>

class Account
{
private:
    int balance; //instance member variable

    // declaring static member variable
    static float roi; //statice member variable //class

public:
    void setBalance(int)
};

void Account::setBalance(int b){
    balance = b;
}

void main(){
    Account a1;

}
```

- toh a1 ek object hai aur uske andar sirf ek hi variable hoga `balance`, `roi` variable object ka part nahi hota iska matlab yeh hai ki **`roi` phir bhi exist karta agar mai koi bhi object nahi batana (just like a1 or something), inshort `Account` me likha hai ek static member variable hai `roi` toh woh program me ek space leke baithe even if `Account` naam ka koi bhi object nahi banaya hua hai.**

> CPP me static member variable ko declare bhar kar dene se variable ko memory nahi milti. Use class ke bahar bhi declare karna zaruri hota hai, taaki use ek memory mile.

- agar aap `float Account::roi = 3.5f;` nahi likhenge toh `roi` naam ka variable nahi banega.
- `roi` ko class ke andar declare karna aur bahar uski definition likhne ke baad hi uss variable ko memory milti hai.
- `roi` variable ki memory object pe depend nahi karti isliye ise class variable kaha jaata hai instance variable nahi kaha jaata hai.

#### Static members part 2

## Static function variable

- static member function sirf static member variables ko hi access kar sakte hai, kyuki yeh

- they are qualified with thte keyword `static`.
- they are also called as class member functions.
- they can be invoked with or without objects.
- they can only access static members of the class.
