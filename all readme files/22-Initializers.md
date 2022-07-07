# Initializers

- initializers list is used to initialize data members of a class.
- The list of members to be initialized is indicated with constructor as a comma separated list followed by a colon.

```cpp
#include <iostream>
using namespace std;

class Dummy{
    private:
        int a;
    public:
    Dummy(){
        a = 5;
    }
};
```

generally constructor ko initialize karne ke liye use kiya jaata hai **initializer list** ka, toh hum constructor ko aise bhi initialize kar sakte hai, but instead of doing this we can use initializer list to initialize our constructor.

```cpp
#include <iostream>
using namespace std;

class Dummy{
    private:
        int a;
    public:
    Dummy():a(5),b(6){
    }
};
```

toh aise use hota hai initializer list ka use, but hum ab question yeh aata hai hum aise kyu karte hai jab hamare pass andar define karne ka option hai. Toh kuch aise cases hai jaha hum andar initialize nahi kar sakte. For example, jab hum `const` type ka variable create karte hai kyuki uski ek shart hai jab bhi hum const type ka variable create karte hai usi samay pe hume usko initialize karna zaruri hai.

for example

```cpp
void fun(){
    const int y = 5;
}
```

agar mai bas `int y` likhta toh yeh toh optional hai ki mai `y` ko initialize karu ya na karu, but wahi jab mai `const int y` likh raha hu toh mujhe initialize karna zaruri hai. Ab `y` ki value wahi rahegi, mai change nahi kar sakta, yaani mai `y++` or `y--` jaise operations bhi nahi kar sakta hu kyuki `y` ki value fix(constant) kar di hai maine.

Wahi agar `const` member variable agar class me banaya jae toh use private ya public me initialize nahi kiya jaa sakta, kyuki CPP ka rule hai ki class banate waqt aap variables yaa members ko initialize nahi kar sakte, uss samay use memory nahi milti. Hum constructor ke andar bhi initialize nahi kar sakte. Toh base yahi ek jagah hai jaaha hume initializer list ka use karna padega. `Const` instance member ko initializer list se hi initialize kiya jaa sakta hai.

---

Now ek aur case hai jaha hume initializer list ka use karna padega. Toh jab bhi hum class ke andar reference variable bana rahe hai, tab bhi hum initializer list ka use kar padta hai. Aur reference variable ko bhi banate hi initialize karna zaruri hai upar se ise bhi banate waqt hi initialize nahi kar sakte hum. Toh hume iske liye initilizer list ka use karna padega.

```cpp
#include <iostream>
using namespace std;

class Dummy{
    private:
        int a , b;
        const int x;
        int &y;

    public:
    Dummy(int n):x(5), y(n){
    }
};

void fun(){
    const int y = 5;
}

int main(){
    int m = 6;
    Dummy obj(m);
}
```
