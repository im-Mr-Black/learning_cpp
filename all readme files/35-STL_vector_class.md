# Vector class in STL

- The most general purpose container is the Vector.
- It supports a Dynamic array.
- What is Dynamic array?

- vector ka matlab yeh hota hai woh container jiski length/space fixed nahi hai, dynamic hai)

## Array and Vector

- array size is fixed, no flexibility to grow or shrink during execution.
- vector can provide memory flexibility.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
   vector<int> v1;
}
```

toh above code me ek vector create ho gaya hai, isme size nahi dena padta hume, yeh ek zero length ka vector hai.

## Initialize during creation

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v1{10,20,30};
}
```

Toh this is how we initialize a vector with values during creation.

toh jub hum blank vector create karte hai, uski length 0 hoti hai, phir jub hum values fill karte hai toh woh apne aap badhti jaati hai. toh 1 value fill karna hai toh no issue 1 block banaega phir usme woh bhar dega, 2 value fill karna hai toh woh 1 block increase karega, waise vector ek ek karke block/capacity increase nahi karta woh double karta hai everytime it runs out of capacity. toh if you have to fill 5 data into blank vector, toh first capacity 1 phir 2 phir 4 phir 8, toh iss case me 5 data fill karne ke baad 3 ke liye space rehega. But wahi jub hum banate waqt hi initialize karte hai, uss case me jitni values hoti hai wahi uski capacity hoti hai(for eg. above case me capacity 3 rahegi not 4) aur agar hum usme values add karte hai baad me toh humari capacity double ho jaega(for eg. above case me 3 ke baad 6 ho jaegi seedha).

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v1{10,20,30};
    vector<int> v2(5);
    vector<char> v3(4, 'a');
    vector<string> v4(4);
}
```

toh in above given code, `vector<int> v2(5);` yeh hum tab use karenge jab hume vector ki length specify karni hai while creation of the vector(totally optional hai yeh sab), wahi jub hume koi vector ki length bhi batani hai and usme kuch dummy data bhi fill karna hai toh hum aise vector create kar sakte hai `vector<char> v3(4, 'a');`, iss case me ek vector create ho jaega 4 length ka jisme character `a` hoga charo boxes me.

---

## Operations on Vector

## Subscript operator []

- subscrip operator is also defined for vector.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<char> v3(4, 'a');
    cout<< v3[0] << endl
        << v3[1] << endl
        << v3[2] << endl;
}
```

### push_back()

- this is a member function, which can be used to add value to the vector at the end.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v3;
    cout << "initial capacity of the vector v3: "<< v3.capacity() << endl;
    v3.push_back(27);
    cout << "capacity of the vector v3 after insertion of value: "<< v3.capacity() << endl;
    v3.push_back(26);
    cout << "capacity of the vector v3 after insertion of value: "<< v3.capacity() << endl;
    v3.push_back(25);
    cout << "capacity of the vector v3 after insertion of value: "<< v3.capacity() << endl;
}
```

Toh isme humne `capacity` function bhi use kar liya hai(yeh capacity of the vector batane ke kaam aata hai), aur humne iss code me yeh bhi jaana ki first capacity zero hoti hai, phir one, phir two and phir four and like that.

### pop_back()

- it removes the last element.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v3;
    for (int i = 1; i <= 9; i++){
        v3.push_back(i*10);
    }
    cout << "current capacity is: " << v3.capacity() << endl;
    v3.pop_back();
    cout << "current capacity after pop is: " << v3.capacity() << endl;
    v3.pop_back();
    cout << "current capacity after pop is: " << v3.capacity() << endl;
}
```

- from above code we get to know 2 things, how to use `pop_back` function and after popping the values the capcity of the vector still remains the same(even if lesser capacity vector is sufficient to store values), for eg. above case me hum tab tak pop karte hai jab tak 7 elements na reh jae(yaani 8 length ka vector is enough) but capacity humare vector ki 16 hi rehti hai. Yaani vector ka size increase hota hai decrease nahi.

### capacity()

- it returns the size of the vector.
- this is the number of elements it can hold before it will need to allocate more memory.

### size()

- it return the number of elements currently in the vector.
- not to confuse with `capacity()` function.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v3;
    for (int i = 1; i <= 9; i++){
        v3.push_back(i*10);
    }
    cout << "current capacity is: " << v3.capacity() << endl;
    v3.pop_back();
    cout << "current capacity after pop is: " << v3.capacity() << endl;
    v3.pop_back();
    cout << "current capacity after pop is: " << v3.capacity() << endl;
    cout << "total number of elements are: " << v3.size() << endl;
}
```

isme hum dekh sakte hai ki capacity 16 dikha raha hai but size 7 hi hai. another use of this function is given below.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v3;
    for (int i = 1; i <= 9; i++){
        v3.push_back(i*10);
    }
    for (int i = 0; i < v3.size(); i++){
        cout << v3[i] << endl;
    }
}
```

### clear() function

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v3;
    for (int i = 1; i <= 9; i++){
        v3.push_back(i*10);
    }
    for (int i = 0; i < v3.size(); i++){
        cout << v3[i] << endl;
    }

    v3.clear();
    cout << "the capacity of the vector is: " << v3.capacity()<<  endl;
    cout << "The size of the vector is: " << v3.size()<<  endl;
}
```

toh this is how we use `clear` function, toh isme hum dekh sakte hai capacity is still 16 while the size is now 0.

### at() function

- This method workd same in case of vector as ti works for array.
- It returns the element at i<sup>th</sup> index in the vector `vecto_name`.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v3;
    for (int i = 1; i <= 9; i++){
        v3.push_back(i*10);
    }
    cout << "the value at third index is: " << v3.at(3) << endl;
}
```

### front() and back() function

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v3;
    for (int i = 1; i <= 9; i++){
        v3.push_back(i*10);
    }
    cout << "the value at third index is: " << v3.at(3) << endl;

    cout << "first value is: " << v3.front() << endl;
    cout << "last valus is: " << v3.back() << endl;
}
```

### Inserting value at some point in the middle of the vector

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v3;
    for (int i = 1; i <= 9; i++){
        v3.push_back(i*10);
    }
    for (int i = 0; i < v3.size(); i++){
        cout << v3.at(i) << endl;
    }

    // here we are gonna use iterator
    vector<int>::iterator it = v3.begin();
    // if we wanna insert value between 20 and 30
    v3.insert(it + 2, 25);
    // toh above line me hamara iterator 2 block aage jaega from the block it is pointing aur phir usse uss block ke aage
    for (int i = 0; i < v3.size(); i++){
        cout << v3.at(i) << endl;
    }
}
```

for this we are gonna use iterator, `vector<int>::iterator it = v3.begin();` so this command will place the pointer to the starting of the vector `v3`. Toh `it` point kar raha hai first block of the vector `v3`.
