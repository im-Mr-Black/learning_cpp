# Pointer

## Object pointer

- a pointer constains address of an object is called Object pointer.
- pointer jiss type ka hota hai usi type ke variable contain karta hai, iska matlab agar pointer `int` type ka hai toh usme `int` ke variable ka address hi rakhna chahie.

```cpp
#include <iostream>
using namespace std;

class Box{
    int l, b, h;
    public:
        void setDimensions(int x , int y , int z){
            l = x;
            b = y;
            h = z;
        }
        void showDimensions(){
            cout << "\nlength: " << l << " breath: " << b << " height: " << h << endl;
        }
};

int main(){
    Box smallBox;
    smallBox.setDimensions(12, 10, 5);
    smallBox.showDimensions();
}
```

- toh yeh ek tareeka hai smallbox naam ke object me value store karne ka. Ab hum dekhenge pointer bana ke agar hum umse value rakhna chahte hai toh kaise rakhenge.

```cpp
#include <iostream>
using namespace std;

class Box{
    int l, b, h;
    public:
        void setDimensions(int x , int y , int z){
            l = x;
            b = y;
            h = z;
        }
        void showDimensions(){
            cout << "\nlength: " << l << " breath: " << b << " height: " << h << endl;
        }
};

int main(){
    Box smallBox , *p;
    p = &smallBox;
    p->setDimensions(12, 10, 5);
    p->showDimensions();
}
```

toh yaha hum dekh sakte hai ki hum kisi object me uss object ka naam use karke bhi value store kar sakte hai, yaa phir hum usko point karne wale pointer ka bhi use kar sakte hai.
pointer ke through value store karne ke liye hum arrow ka use karenge(`->`). Toh dot(`.`) use hoga object ke saath aur arrow(`->`) use hoga pointer ke saath.

`p->setDimensions(12, 10, 5);` iska inference yeh hai ki pointer `p` jo hai woh `setDimension` ko call kar raha hai aur kuch value store karna chah raha hai but woh kis cheez ke liye yeh function run karega, toh `setDimension` uss object ke liye run karega jise pointer `p` point kar raha hai.

## this pointer

- `this` is a keyword.
- `this` is local object pointer in every instance member function constaining address of the caller object.
- `this` pointer can't be modified.
- it is used to refer caller object in member function.
- har class me kisi bhi function ke andar ek `this` naam ka pointer hota hi hai, aap nahi banate woh by default hota hai.

```cpp
#include <iostream>
using namespace std;

class Box{
    int l, b, h;
    public:
        void setDimensions(int l , int b , int h){
            this->l = l;
            this->b = b;
            this->h = h;
        }
        void showDimensions(){
            cout << "\nlength: " << l << " breath: " << b << " height: " << h << endl;
        }
};

int main(){
    Box smallBox , *p;
    p = &smallBox;
    p->setDimensions(12, 10, 5);
    p->showDimensions();
}
```

toh idhar `this` pointer ka use hum `setDimensions` me dekh sakte hai. Toh agar dhyaan se dekhe toh hum yeh dekh sakte hai ki `setDimensions` function ke local variable aur class `Box` ke instance member variable, dono ka naam same hai. Toh jab hum normal way me code kar rahe honge tab hamara code kuch aisa dikhega `setDimensions` ke andar

```cpp
l = l;
b = b;
h = h;
```

yaha pe name conflict ho raha hai.
toh yeh dekh ke compiler yeh sochega ki jo `l` ,`b` aur `h` hai woh `setDimension` ke hi hai, but hum yeh chahte hai ki local variable me jo `l` hai woh jaake class ke instance member variable `l` ko assign ho jae.
