# Map

- maps are used to replicate associative arrays.
- maps contain sorted key-value pair, in which each key is unique and con't be changed, it can be inserted or deleted but cannot be altered.
- toh 2 tareeke ke arrays hote hai, numeric and associative arrays.
  - toh arrays jisme blocks me data bharne ke liye index number pata hona chahie unhe hum numeric arrays bolte hai(numeric arrays ka matlab hai inme indexing number se hogi)
  - basically dictionary of python is associative, isme key-value pair se data store hota hai. Key iss data type ka index hai, toh iss case me fayda yeh hota hai ki hum key dalenge aur usse related values hume mil jaegi, isme woh value access karne ke liye hume index number nahi pata karna padega.

## Maps

- isme hum key-value pair se data store karte hai woh toh theek hai. Isme hum key ka naam/value change nahi kar sakte hai but key se related value change ki jaa sakti hai.(value associated to the key can be changed).
- maps always arrange its keys in sorted order.
- In case the keys are of string type, they are sorted in dictionary order.

## Operations on Maps

### creation/insertion of Map

- empty dictionary

```cpp
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, string> customer;
}
```

- inserting value in the dictionary after creation

```cpp
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, string> customer;
    customer[100] = "gajendra";
    customer[123] = "dilip";
    customer[145] = "aditya";
    customer[171] = 'shahid';
    customer[200] = "rajesh";
}
```

- inserting values while creation

```cpp
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, string>c{
        {100  , "gajendra"},
        {123 , "dilip"},
        {145 , "aditya"},
        {127 , "shahid"},
        {200 , "rajesh"}
    }
}
```

## Useful functions of map class

### [] function

```cpp
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, string> customer;
    customer[100] = "gajendra";
    customer[123] = "dilip";
    customer[145] = "aditya";
    customer[171] = 'shahid';
    customer[200] = "rajesh";

}
```

toh agar hum dekhe toh `customer[100]` pe toh obvious `gajendra` cout ho raha hai, but wahi `101` naam ki koi key nahi hai, toh yeh koi error bhi nahi throw karega aur value bhi print nahi karega.

- Toh agar hume saari value print karani hai, toh humne iterator ka use karna padega(cause isme values line by line toh hai nahi ki hum for loop me `i` daal ke values nikalte jae). Toh dekhte hai how to print all the value of a map using iterator.

```cpp
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, string> customer;
    customer[100] = "gajendra";
    customer[123] = "dilip";
    customer[145] = "aditya";
    customer[171] = "shahid";
    customer[200] = "rajesh";

    auto p = customer.begin();
    while (p != customer.end())
    {
        cout << p->second << endl;
        p++;
    }
}
```

toh this is how we can print all the values of a map. `cout << p->second << endl;` iss line me `second` ka matlab hai p point kar raha hai first index of the map.
Matlab agar hume key chahie toh hum `first` lekhenge aur agar hume value chahie toh second aur agar jaada values contain karta hai woh toh hum third fourth and so on.

### at() function

```cpp
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, string> customer;
    customer[100] = "gajendra";
    customer[123] = "dilip";
    customer[145] = "aditya";
    customer[171] = "shahid";
    customer[200] = "rajesh";

    cout << customer.at(123);
}
```

toh this is how we use `at` function.

### size() function

```cpp
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, string> customer;
    customer[100] = "gajendra";
    customer[123] = "dilip";
    customer[145] = "aditya";
    customer[171] = "shahid";
    customer[200] = "rajesh";

    cout << customer.size();
}
```

### empty() function

- this function tells if the map is empty.

```cpp
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, string> customer;
    customer[100] = "gajendra";
    customer[123] = "dilip";
    customer[145] = "aditya";
    customer[171] = "shahid";
    customer[200] = "rajesh";

    cout << customer.empty();
}
```

this will o/p zero(0) that means the map is not empty, if it returns 1 then it means the map given is empty.

### clear() function

- this function will clear all the values that are inside the map.

### insert() function

```cpp
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, string> customer;
    customer[100] = "gajendra";
    customer[123] = "dilip";
    customer[145] = "aditya";
    customer[171] = "shahid";
    customer[200] = "rajesh";

    customer.insert(pair<int, string> (205, "Shubham"));
}
```

toh this is how we insert a new data in map, well hume yeh bhi dhyaan dena padega ki pair ka use karna hai, also hume data type bhi define karna padega.
