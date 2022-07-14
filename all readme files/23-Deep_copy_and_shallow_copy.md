# Deep Copy And Shallow Copy

## what is copy and how can we create a copy of an object?

```cpp
#include <iostream>
using namespace std;

class Dummy{
    private :
        int a, b;
    public:
    void setData(int x , int y){
        a = x;
        b = y;
    }
    void showData(){
        cout << "\na = " << a << " b= " << b << endl;
    }
};

int main(){
    Dummy d1;
    d1.setData(3, 4);
    Dummy d2 = d1;
    d2.showData();
}
```

toh jab `d1` bana hoga toh use kuch memory mili hogi, iske ander 2 variable the `a` and `b` ko bhi memory mili, phir humne usme kuch values bhi bhar di. Now, jab humne phir se dummy class ka object banaya `d2` tab humne usko `d1` se initialize kar diya. Toh `d1` ka saara data `d2` me chala gaya aur yeh hua copy karne ka operation(yeh shallow copy tha waise).

But now copy kaise hota hai, copy 2 tareeke se hota hai, ya toh call hota hai copy constrctor or call hota hai default assignment operator(Implicit copy assignment operator), toh inn dono me se koi ek call hoga jab bhi hum object copy karenge.

Now above given code me copy constrctor call hua hai. kyuki we wrote `Dummy d2 = d1` define hote hi assign kar diya humne ise values bhi. Hum nahi banate but compiler humari taraf se ek copy constructor khud hi bana deta hai. Toh d2 me values copy constructor ki madad se hui hai. Toh copy constructor tab call hota hai jab hum koi object bana rahe hai aur phir usi class ke object se initialize kar rahe hai(here d1 and d2 both are from dummy class).

Ab, agar hum kuch aisa code karte

```cpp
Dummy d2;
d2 = d1;
```

toh case kuch aur hota,iss case me constructor nahi chalta kyuki constructor tab chalta hai jab object initialize hota hai, toh iss case me operator overloading ho jaati hai(yeh operator overloading ki definition bhi hum nahi likhte yeh compiler khud hi kar leta hai) Toh jab humne `d2 = d1` likha tab implicit copy operator chala aur d1 ki values d2 me chali gai.

Toh now its clear ki copy constructor se kab ho raha hai aur implicit copy operator se kab ho raha hai.

## how can we make a copy constructor

```cpp
#include <iostream>
using namespace std;

class Dummy{
    private :
        int a, b;
    public:
    void setData(int x , int y){
        a = x;
        b = y;
    }
    void showData(){
        cout << "\na = " << a << " b= " << b << endl;
    }
    Dummy(Dummy &d){
        a = d.a;
        b = d.b;
    }
};

int main(){
    Dummy d1;
    d1.setData(3, 4);
    Dummy d2 = d1;
    d2.showData();
}
```

toh this is how the constructor inside the class will look like when we are gonna create a copy constructor.

## Shallow copy

- creating copy of object by copying data of all member variables as it is.

## Deep copy

-
