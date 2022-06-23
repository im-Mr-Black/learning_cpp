# Operator Overloading

- When an operator is overloaded with multiple jobs, it is known as operator overloading.
- It is a way to implement compile time polymorphism.

## Rules to remember

- Any symbol can be used as function name.

  - if it is a valid operator in C language.
  - if it is preceded by operator keyword.

- You can not overload `sizeof` and `?:` operator.

---

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
        cout << "\na: " << a << " b: " << b;
    }
    Complex operator +(Complex c){
        Complex temp;
        temp.a = a + c.a;
        temp.b = b + c.b;
        return temp;
    }
};

int main(){
    Complex c1, c2, c3;
    c1.setData(3, 4);
    c2.setData(5, 6);
    c3 = c1.operator+(c2);
    c3 = c1 + c2;
    c3.showData();
}
```

`c3 = c1 + c2;` and `c3 = c1.operator+(c2);` both are same and they both mean the same as well.

### Operator overloading part 2

aise operator jisme 2 operands ki requirement hoti hai unhe hum **binary operator** bolte hai. ab hum **unary operator** ko dekhenge, isme sirf ek hi operand ki jarurat hoti hai.

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
        cout << "\na: " << a << " b: " << b;
    }
    Complex operator -(){
        Complex temp;
        temp.a = -a;
        temp.b = -b;
        return temp;
    }
};

int main(){
    Complex c1, c2, c3, c4;
    c1.setData(3, 4);
    c2.setData(5, 6);
    c3 = -c2;
    c4 = c1.operator-();
    c3.showData();
    c4.showData();
}
```

unary operator me caller object hi iska iklauta operator hota hai isliye isme hum argument pass nahi karte.
`c3 = -c2;` and `c4 = c1.operator-();` dono hi same tareeke hai overloading ke.

## Operator overloading part 3

- aaj hum increment operator(++) ki overloading(pre aur post overloading).

```cpp
#include <iostream>
using namespace std;
class integer{
    private:
        int x;

    public:
        void setData(int);
        void showData();
        integer operator++();
};

void integer::setData(int a){
    x = a;
};
void integer::showData(){
    cout << "x: " << x << endl;
};
integer integer::operator++(){
    integer i;
    i.x = ++x;
    return i;
};

int main(){
    integer i1 ,i2;
    i1.setData(3);
    i1.showData();
    i2 = ++i1;
    i1.showData();
    i2.showData();
}
```

isme focusing on the coding of the pre-increment part that we wrote.

```cpp
integer integer::operator++(){
    integer i;
    i.x = ++x;
    return i;
};
```

isme hum yeh keh rahe hai we make a arbitrary `integer i` ,then jo hamara caller object hai uska `x` pre-increment hoke hamare arbitrary `integer i` ke `x` ko assign ho jae. Fir hum hamara arbitrary `i` ko return kar denge.

---

toh yeh toh thi simple coding for pre-increment operator, but problem yaha aati hai jab hum post increment ka coding karne jaenge toh dono pre aur post ki definition call same ho jaegi, toh isse compiler yeh nahi decide kar paega ki kiska meaning pre hai aur kiska meaning post hai.

CPP me ek naya rule hai to tackle this ki hame ek `int` pass karna hoga taaki compiler ko yeh pata chal sake yeh post increment ke liye bana hua operator hai.

aur yeh `int` bas naam bhar ke liye rakhna hai uska koi use nahi hai, yaani hame actual me koi value pass karni nahi hai.

```cpp
#include <iostream>
using namespace std;
class integer{
    private:
        int x;

    public:
        void setData(int);
        void showData();
        integer operator++();    //pre increment
        integer operator++(int); //post increment
};

void integer::setData(int a){
    x = a;
};
void integer::showData(){
    cout << "x: " << x << endl;
};
integer integer::operator++(){
    integer i;
    i.x = ++x;
    return i;
};
integer integer::operator++(int){
    integer i;
    i.x = x++;
    return i;
};

int main(){
    integer i1 ,i2;
    i1.setData(3);
    i1.showData();
    i2 = ++i1;
    i1.showData();
    i2.showData();
    i2 = i1++;
    i1.showData();
    i2.showData();
}
```

isme yaha pe focus karna ki zarurat hai

```cpp
integer integer::operator++(int){
    integer i;
    i.x = x++;
    return i;
};
```

isme hum pehle caller object ka `x` hamare `i` me pass kar denge, then usme increment hoga, toh yeh post increment jaise hi kaam kar raha hai.

toh bas yahi baat hai bina `int` wala pre-increment ke liya use hoga aur jisme `int` hai woh post increment ke liye use hoga. Yeh compiler ke liye hai taaki woh inn dono me fark jaan sake baaki iss `int` ka koi use nahi hai.
