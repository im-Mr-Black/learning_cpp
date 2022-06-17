# Classes and Objects

- The only difference between structure and class is that
  - the members of structures are by default public,
  - while the members of class are by default private.

```cpp
#include <iostream>
using namespace std;

struct complex
{
    private:
        int a, b;
    public:
    void set_data(int x , int y){
        a = x;
        b = y;
    }
    void show_data(){
        cout<< "\na= " << a << ", "
            << "b= " << b;
    }
};



int main(){
    complex c1;
    c1.set_data(3, 4);
    c1.show_data();
}
```

here if we change `struct` to `class` that won't make much difference, the only thing is, now everything is by default private.

```cpp
#include <iostream>
using namespace std;

class complex  //changes made over here
{
    private:
        int a, b;
    public:
    void set_data(int x , int y){
        a = x;
        b = y;
    }
    void show_data(){
        cout<< "\na= " << a << ", "
            << "b= " << b;
    }
};



int main(){
    complex c1; // here c1 is an object
    c1.set_data(3, 4); //noun.verb == that is c1 pe data set karna hai(aisa kuch)
    c1.show_data(); //similarly c1 ka show data
}
```

- jab cpp me class ka concept hai toh structure ka concept abhi bhi kyu hai?

Toh iska yeh answer ho sakta hai ki `C` language me structure ka concept hai class ka nahi toh backward compatibility provide karne ke liye `CPP` me class aur structure dono ka concept hai.

- class ki madad se bane data type `complex c1` variable na kehla ke object kehlaega
- class koi memory consume nahi karta, object memory consume karta hai.

---

```cpp
#include <iostream>
using namespace std;

class Complex
{
private:
    int a, b;

public:
    void set_data(int , int);
    void show_data(int , int){
        cout << "\na" << a << " b" << b;
    }
};
// defining function outside the class complex
void Complex:: set_data(int x , int y){
    a = x;
    b = y;
}

int main(){
    Complex c1;
    c1.set_data(3, 4);
    c1.show_data();
}
```

let us say ki mai koi function class ke bahar define karna chah raha hu(for example here `void set_data`), toh normally kya problem hota hai ki woh member function nahi maaana jaaega kyuki woh bahar defined. But mai chahta hu ki woh member function maana jaae toh mujhe kuch sharte maani padegi jaise: - aapko function ko andar declare karna hoga aur - jab function ko bahar define kar rahe hai tab, function ke return type aur function ke name ke beech me membership label lagaya jaega. Toh isse yeh maana jaega ki yeh jo function hai woh bahar defined hai but uss particular class ka member hai.
The only difference in this case is jab aap function ko andar define karte hai tab woh by default inline hota hai but jab aap bahar define karte hai tab aapko `inline` declaration keyword likhna padta hai, iske aalawa isme koi difference nahi hota hai.

---

#### Part 3

```cpp
#include <iostream>
using namespace std;
class Complex
{
private:
    int a, b; //instance variable
public:
    void set_data(int , int);
    void show_data(int , int){
        cout << "\na" << a << " b" << b;
    }
    Complex add(Complex c){
        Complex temp;
        temp.a = a + c.a;
        temp.b = b + c.b;
        return (temp);
    }
};
// defining function outside the class complex
void Complex:: set_data(int x , int y){
    a = x;
    b = y;
}
int main(){
    Complex c1, c2 , c3;
    c1.set_data(3, 4);
    c2.set_data(5, 6);
    c3 = c1.add(c2);
    c3.show_data();
}
```

Instance aur object same hi baat hai.

- jo variables humne class ke andar banae hai woh class variable nahi hai, unhe hum instance member variable kehte hai(instance ke variable or object ke variable).
- c1 ke andar a aur b alag hounge , c2 ke andar a aur b alag hounge aur c3 ke andar ke alag, isliye inhe instance member variable kaha jaa raha hai, har variable ke liye alag alag.
- isi tareeke se humne jo functions andar banae hai unhe hum instance member functions bulate hai.

> State - kisi bhi object variable ki

:: --> scope resolution operator
