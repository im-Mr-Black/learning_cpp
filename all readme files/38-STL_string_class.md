# String class

## Traditional way

- using null-terminated character arrays are not technically data types.
- so cpp operators can't be applied to them.

- `char s1[10] , s2[10];`

- C language me string jo hai woh sequence of character hai but last character must be null character(this is important) if the last character is not null character then technically it is not a string.Yeh cheez CPP ne directly adopt kar li.(null is like full stop).

```cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
    char s1[10] = "hello";
    s1 = "Students"; // wrong
    char s2[20];
    s2 = s1; //wrong
}
```

toh hum yeh sab nahi kar sakte hai kyuki yeh basically ek array hi hai, and we can't perform these operations on an array.

```cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
    char s1[10] = "hello";
    strcpy(s1, "student"); //right
}
```

toh yeh sab functions ka use karna padta hume for all these operations and yeh sab pain in ass hai toh isse deal karne ke liye CPP me string class banai gai.

---

## String class

- the string class is a specialization of a more general template class called **basic_string**.
- since defining a class in cpp is creating a new data type, string is derived data type.
- this means operator can be overloaded for the class.
- string class is an another container class.
- to use string class, you have to include string header
  - `#include <string>`
  - `string.h` aur `string` dono different hai. jaise `strcpy()` function agar use karna hai toh hume `string.h` use karna padega but wahi agar hume bas string class ko use karna hai toh hum bas `string` likhenge.

### why is char array not removed from cpp

- yeh baat toh ekdam sahi hai ki string class ne kaafi problems solve kar di char array me aati thi but dono ke apne fayde ghate hai.
- string pe jo operation ho rahe hai woh safe toh hai but time consuming hai,agar hum char array ka use karke characters handle karte hai directly then speedly kaam karega kyuki hum iss case me kam operations perform karte hai basic raw style se.
- **toh when to use string class and when to use char array?** toh jab bhi speed matter karti ho toh char array use kare aur jab hume safety jaada matter karti ho safty of data(data security) aur easy manipulation karna ho string ka(jaada code na likhna pade) then string class use karna sahi rahega.

## string class is safer than char array

- careless programmer can overrun the end of an array that holds a null terminated string.

```cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
    char s1[10];
    strcpy(s1, "hello online student"); //common blunder
}
```

toh iss case me hum dekh sakte hai ki jo array hai usme sirf 10 blocks hai for storing character but humne jo string pass ki hai uske 10 is less toh iss case me woh baaki ki string ko phek dega and data loss ho jaega.

- for example, using strcpy()
- string class handles such issues.

### creation of object using string class

```cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
    string s1 = "hellow";
}

```

## Constructor

- string class supports many constructor, some of them are:
  - string()
  - string(const char \*s)
  - string(const string &str)

```cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
    string s1 = "hello";
    string s2 = string("hellow");
    string s3("hellow");
}
```

toh upar diye gae teeno tareeke ek hi hai.

## Operator in String

- `=` assignment
- `+` concatenation
- `+=` contatenation assignment
- `==` equality
- `!=` inequality
- `<` less than
- `<=` less than or equal
- `>` greater than
- `>=` greater than or equal
- `[]` subscripting

```cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
    string s1;
    s1 = "hello";
    string s2 = " students";
    s2 = s1 + s2; // concatenation
    s2 += s1; //above line and this line is same
}
```

---

### String part 2

## use of insertion and extraction operator

```cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
    string s1;
    s1 = "hello";
    string s2 = " students";
    string s3;
    s3 = s1 + s2; // concatenation
    cout << s1 << endl
         << s2 << endl
         << s3;
    cout << "enter your name: ";
    string s4;
    cin >> s4;
    cout << "hello, " << s4;
}
```

- so, ek baat dhyaan rakhni hai hume ki jub bhi hum insertion operator use karenge toh woh sirf single word input hi lega. jaise `cin >> s4;` me agar mai `shubham sherki` toh string `s4` me sirf shubham hi aaega(space ko woh delimator maanta hai).

## Mixed Operations

- you can mix string objects with another string objects or c style string.
- CPP string can also be concatenated with character constant.

```cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
    string s1 = "hello";
    char str[] = "students";
    string s2;
    s2 = s1 + str;
    cout << s2;
}
```

## Useful methods

### assign()

```cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
    string s1;
    s1.assign("Hello");
    cout << s1;
}
```

### append() function

```cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
    string s1 = "kahe ka ";
    s1.append("Hello");
    cout << s1;
}
```

### insert() function

```cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
    string s1 = "kahe ka ";
    s1.insert(2,"shubham");
    cout << s1;
}
```

- toh isme 2 ka matlab hai 2<sup>nd</sup> se chalu karke hume as an argument diye gae string ko insert karna hai(toh o/p will be `kashubhamhe ka`, isme yeh bhi dekh sakte hai ki humara diya gaya string original string ki jagah pe aa gaya aur bacha hua string shift hogaya right ki taraf toh `shubham` ke baad original string ka bhi part dikh raha hai.

### replace()

```cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
    string s1 = "kahe ka ";
    s1.replace(1, 3, "A");
    cout << s1;
}
```

toh agar upar wale code ko hum run karenge, toh hum yh dkh sakt hai ki

### erase()

- this function will everything(if no argument is passed)

```cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
    string s1 = "kahekahe ";
    s1.replace(1, 3, "A");
    cout << s1 <<endl;
    s1.erase(3);
    cout << s1;
}
```

- this will erase everything after index number 3(including it)

### find() function

- toh yeh function koi bhi string input me lega aur agar woh string given string me exist karti hai toh woh uska first occurance return kar dega(if there are multiple occurance). Agar argument wali string given string me nahi hai toh `-1` or `string::npos` return kar dega yeh function.

```cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
    string s1 = "hello online online students";
    int i = s1.find("online");
    cout << i << endl;
    int j = s1.find("SHubham");
    cout << j;
}
```

### rfind() function

- toh yeh find function hi hai bas reverse me find karta hai, yaani peeche se start karke yeh first occurance dekhta hai argument wali string ka.

### compare() function

- toh yeh function do strings ko compare karne ke liye use hota hai.
- agar string same hai toh yeh function `0` return karega
- and if string same nahi hai toh yeh function `-1` or `+1` return karta hai.(dictionary order me hai yaani `s1.compare(s2)` me `s1` pehle aaega dictionary me and then `s2` aaega toh `-1` return hoga and if `s2` pehle aaega `s1` se according to dictionary then `+1` return hoga).

```cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
    string s1 = "amar";
    string s2 = "amar";
    int i = s1.compare(s2);  // returns 0
    cout << i;
}
```

```cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
    string s1 = "amit";
    string s2 = "amar";
    int i = s1.compare(s2); // return 1
    cout << i;
}
```

### c_str() function

- toh yeh function will

```cpp
#include <iostream>
#include <string>
#include <string.h>
#include <array>
using namespace std;

int main(){
    string s1 = "hell0";
    char str[20];
    strcpy(str, s1.c_str());
    cout << str;
}
```

### size() function

```cpp
#include <iostream>
#include <string>
#include <string.h>
#include <array>
using namespace std;

int main(){
    string s1 = "hell0";
    int i = s1.size();
    cout << i;
}
```

- toh this function will return `5` jab hum upar wala snippet run karenge. toh yeh string ka length return kar dega.
