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
    c1.set_data(3, 4);`//noun.verb == that is c1 pe data set karna hai(aisa kuch)
    c1.show_data(); //similarly c1 ka show data
}
```

- class ki madad se bane data type `complex c1` variable na kehla ke object kehlaega
- class
