# Type Conversion

## Primitive type to class type

- int, char , float, double are primitive types.
- class typs is any class you defined.
- toh yeh sab toh already defined hai, compiler bhi inhe jaanta hai. Jab bhi hum class banate hai toh yeh ek naya data type hota hai woh hai secondary type/class type.Toh jab bhi hum class bana rahe hote hai toh hum ek data type bana rahe hote hai.

## Why conversion is required?

```cpp
//code 1
int x=4;
float y;
y = x; //automatic type conversion


// code 2
float y = 3.4;
int x;
x = y;  //automatic type conversion
```

toh yeh hona nahi chahie but yeh automatically type conversion ho jaega. Code 1 me y = 4.0 ho jaega wahi code 2 me y = 3(data loss hoga) ho jaega.

> toh jab bhi hum type conversion kar rahe hote hai toh data loss ho sakta hai.

---

Toh agar primitive to primitive conversion ho raha hai, toh koi bhi problem nahi hai, but jaise hi primitive to class or class to primitive or class to class hota hai toh compiler khud ba khud yeh sab nahi kar paata aur phir aati hai error. Toh abhi hum yahi dekhenge.

```cpp
#include <iostream>
using namespace std;

class Complex{
    private:
        int a, b;
    public:
    void setData(int x, int y){
        a = x;
        b = y;
    }
    void showData(){
        cout << "\na: " << a << " b: " << b << endl;
    }
};

int main(){
    Complex c1;
    int x = 5;
    c1 = x;     //error
    c1.showData();
}
```

toh `c1=x;` wali line pe aaegi error, toh ise hum kaise durr karenge? Toh iska answer hai **Constructor**.

```cpp
#include <iostream>
using namespace std;

class Complex{
    private:
        int a, b;
    public:
    void setData(int x, int y){
        a = x;
        b = y;
    }
    void showData(){
        cout << "\na: " << a << " b: " << b << endl;
    }
    Complex(int k){
        a = k;
        b = 0;
    }
    Complex(){}
};

int main(){
    Complex c1;
    int x = 5;
    c1 = x;
    c1.showData();
}
```

Toh ab humne banaya ek constructor jo ki argument le raha hai. Toh woh `int` type ka argument accept karta hai. Toh jo humne line likhi thi `c1= x;` woh error nahi degi aur agar acche se dekha jae toh iss line ka matlab yeh hoga ki `c1` object bana hai aur usme constructor call hua hai argument wala aur phir jo bhi uss constructor ki coding hogi uss hisab se compiler data manipulate kar lega.

Toh `c1` me `x` ke value copy ho gai but woh copy humare style se hui hai.

> Toh constructor call iss tareeke se bhi ho raha hai yeh humne abhi jaana. Toh yeh hai jab hume type conversion karna hai from primitive to class type.

## Class type to Primitive type

- toh phir se jab hum primitive to class type me conversion karne ki koshish karenge, toh aaegi error.

```cpp
#include <iostream>
using namespace std;

class Complex{
    int a, b;
    public:
    void setData(int x , int y){
        a = x;
        b = y;
    }
    void showData(){
        cout << "\na: " << a << " b: " << b << endl;
    }
};

int main(){
    int x;
    Complex c1;
    c1.setData(3, 4);
    x = c1; // error
    cout << "\nx: " << x << endl;
}
```

toh isme error aaegi `x = c1` wali line pe.Toh iss error ko kaise durr kare? Toh iska answer hai **Type casting**. Toh hum use karenge **casting operator**. Isme hum `operator` keyword ka use karenge. Toh ab hume `operator` keyword ke 2 use pata hai, operator overloading aur type casting.

Syntax:

```cpp
operator type(){
    // your code over here
    return (type-data);
}
```

---

```cpp
#include <iostream>
using namespace std;

class Complex{
    int a, b;
    public:
    void setData(int x , int y){
        a = x;
        b = y;
    }
    void showData(){
        cout << "\na: " << a << " b: " << b << endl;
    }
    operator int(){
        return (a);
    }
};

int main(){
    int x;
    Complex c1;
    c1.setData(3, 4);
    x = c1;
    cout << "\nx: " << x << endl;
}
```

- Toh ab logic kya hai iske peeche, toh operator keyword likha hai aur phir variable ke type likhna hai jisko hume data assign karna hai(here x is `int` toh humne `int` likha, agar float hota toh float likhte, char hota toh char likhte). Phir andar hum kuch bhi code karenge not a problem but hum jo bhi return kar rahe honge hume yeh yaad rakhna hai uska data type aur variable ke data type same ho. Here we are return value of `a`, toh yeh toh object `c1` pe run hua hai toh hum c1 ke objects directly likh sakte hai.Toh yeh sab likhna hai class ki body ke andar.(iska explainatin maine acche se nahi kiya hai ig. iska video dekh lena)
  [link to that video](https://www.youtube.com/watch?v=RPRXbJ5Qjys&list=PLLYz8uHU480j37APNXBdPz7YzAi4XlQUF&index=57)

## One class type to another class type

- toh hum one class se another class me data copy karne chahte hai, but again hum directly copy karne jaaenge toh compiler yeh task nahi kar paega, aur error throw kar dega.Toh hum yeh task kaise karenge? toh iss task ko hum 2 tareeke se kar sakte hai:
  - conversion through constructor
  - conversion through casting operator

Toh iss case hum dono tareeke se data copy kar sakte hai.Ab hum ek case lete hai:

```cpp
Item i1;
Product p1;
p1.setData(3,4);
i1 = p1;
```

Toh agar hum constructor bana ke data copy karne ki koshish karenge toh `i1 = p1;` line ko dekh ke hum bata sakte hai ki hume constructor item class me banana padega(yaani uski class me jo equal to ke left side me hai), wahi agar hume casting operator kar use karke product class se item class me data copy karna hai toh hum casting operator ki coding product class me karenge.

Toh hum using Constructor kaise copy karenge one class to another class

```cpp
#include <iostream>
using namespace std;
class Product{
    int m, n;
    public:
        void setData(int a , int b){
            m = a;
            n = b;
        }
        void showData(){
            cout << "\na: " << m << " b: " << n;
        }
        int getM(){
            return m;
        }
        int getN(){
            return n;
        }
};
class Item{
    int a, b;
    public:
        void setData(int a , int b){
            this->a = a;
            this->b = b;
        }
        void showData(){
            cout << "\na: " << a << " b: " << b;
        }
        Item(Product p){
            a = p.getM();
            b = p.getN();
        }
        Item(){}
};


int main(){
    Item i1;
    Product p1;
    p1.setData(3,4);
    i1 = p1;
    i1.showData();
}
```

toh hum 2 kaam karne hai, item class me 2 constructor banane honge ek empty(taaki hum item class ka object bana sake w/o any argument) aur ek copy constructor taaki hum product class ka data item class me copy kar sake.

Toh ab agar hum dhayaan hum normally code karne jaate toh hum `a = p.m; b =p.n;` likh ke nikal jaate but the thing is `m` and `n` are private variables of product class toh hum inn dono ko item class me directly nahi use kar paenge. To tackle this hume product class me 2 public function banane honge jo `m` aur `n` ki value return karte ho, so that we can use them in itme class. Now we are good to go.

---

Now let us look at the part when we want to use casting operator to copy data from one class to another class.

```cpp
#include <iostream>
using namespace std;
class Item{
    int a, b;
    public:
        void setData(int a , int b){
            this->a = a;
            this->b = b;
        }
        void showData(){
            cout << "\na: " << a << " b: " << b;
        }
};

class Product{
    int m, n;
    public:
        void setData(int a , int b){
            m = a;
            n = b;
        }
        void showData(){
            cout << "\na: " << m << " b: " << n;
        }
        operator Item(){
            Item temp;
            temp.setData(m, n);
            return temp;
        }
};
int main(){
    Item i1;
    Product p1;
    p1.setData(3,4);
    i1 = p1;
    i1.showData();
}
```

toh since equality sign ke right side me product class ka object hai toh hum casting operator ki coding product class me karenge. Toh bas hum yeh dhyaan rakhna hai ki `operator` keyword ke baad Item class likhenge aur phir hum usi(item) class ka object bana ke uspe `setData` wala function laga denge jisme hum `m` aur `n` pass karenge.
