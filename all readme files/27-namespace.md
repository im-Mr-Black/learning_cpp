# Namespace

accha jab hum CPP me code karna chalu kar rahe hote hai usse pehle hum likhe hai `#include <iostream>` or `#include <stdio.h>` iska matlab kya hai? yeh hai ek header file.

**what is header file?** header file woh hai jisme identifiers ke declaration hote hai. Toh declaration kaafi tarah ke shabd ka hota hai. Jaise `printf` ka declaration `stdio.h` me hai but uska defintion kisi aur file me hota hai(library file me hota hai definition). Toh header file me functions ka declaration hota hai definition nahi hoti. Toh header file me kaafi tarah ke identifiers ke declaration hota hai definition nahi hota.

now question arises, **why do we include header files in our program?** toh hum inhe include iss liye karte hai taaki jub hum identifiers/functions/variables ka use karte apne program me toh compiler ko yeh na lage ki yeh undefined word/keyword hai aur yep pata ho ki yeh word kya hai, isliye inn sab keywords ka declaration karna zarur hai.

**Namespaces ka concept**: namespace basically declarations ka group hai, namespace ek keyword bhi hai aur namespace keyword ke use se mai koi naam ka namespace bhi bana sakta hu.

**question namespace me conflict nahi ho jab same naam ke variable 2 namespaces me hai, woh kaise hoga**

## Namespace

- namespace is a container for identifier.
- it puts the names of its members in a distinct space so that they don't conflict with the names in other namespaces or global namespaces.

## How to create namespace?

**SYNTAX**

```cpp
namespace Myspace{
    //declarations
}
```

- namespaces definition doesn't terminates with a semicolon like in class definition.
- The namespace definition must be done at global scope or nested inside another namespace.
- you can use an alias name for your namespace name, for ease of use
- for example `namespace ms = Myspace;`

---

- There are unnamed namespace too.

**SYNTAX**

```cpp
namespace{
    //declaration
}
```

---

- namespaces can be extended, i.e. A namespace definition can be continued and extended over multiple files, they are not redefined or overridden.
- agar hum 2 header file banae jisme ek hi naam ke namespace hai toh compiler 2 alag alag namespace nahi banaega balki woh dono ko combine karke ek hi scope bana dega (isi ko bolte hai namespaces can be extended).

### namespace part 3

```cpp
#include <iostream>
using namespace std;

namespace Myspace{
    int a;
    int f1();
    class A{
        public:
            void fun1();
    }
}

int main(){

}
```

toh humne abhi `Myspace` me 3 tareeke ki cheeze banai hai, variable , function aur class bhi (accha yeh namespace abhi humne source file me likha hai, yeh hum ek header file me bhi likh sakte hai).

Ab hum chahte hai ki `a` ko access kar sakte toh agar hum directly `a = 5` likh denge toh error aaegi. Hum directly access nahi kar sakte hai namespace ke kisi bhi member ko. Humne scope resolution operator ka use karna padega to access any member of that namespace.

> accha jo `cout` hai, woh iostream(not iostream.h) me hoti hai. Toh iostream me ek namespace hai `std` naam ka usme yeh `cout` ka declaration hai.

```cpp
#include <iostream>
using namespace std;
namespace Myspace{
    int a;
    int f1();
    class A{
        public:
            void fun1();
    };
}

int Myspace::f1(){
    std::cout << "hello" << endl;
}
void Myspace::A::fun1(){
    cout << "hello fun1";
}

using namespace Myspace;
int main(){
    Myspace::a = 5;
    f1();
    A obj;
    obj.fun1();
}
```

- any name(identifier) declared in a namespace can be explicitly specified using the namespace's name and the scope `resolution::operator` with the identifier.

---

## The using directive

- `using` keyword allows you to import an entier namespace into your program with a global scope.
- It can be used to import a namespace into another namespace or any program.
  ![example](/all%20readme%20files/images/namespace.png)

Toh yaha pe hum dekh sakte hai ki humne ek `MySpace` naam ka ek namespace banaya hua(aur use humne ek header file ki tarah save bhi kar diya hai, `File1.h`) hai jisme kuch members bhi hai. Now hum `File1.h` ko `File2.h` me import kar rahe hai, toh isse kya hoga MySpace ke saare members yaani saare variables import ho jaenge. Phir humne yeh bhi likh diya hai `using namespace MySpace` isse hum MySpace ke saare members ko access kar paenge w/o scope resolution operator.(toh isme humne `MyNewSpace` me ek name space import kiya hai).
