# STL List

- list class supports a bidirectional, linear list.
- vector supports random access but a list can be accessed sequentially only.
- list can be accessed front to back or back to front.

### Creating empty list

```cpp
#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l1;
}
```

### initializing a list

```cpp
#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l1;
    list<string> l2("India", "dhaka", "new delhi");
}
```

### printing out values from the list

we have to use iterator to print out the data that is in the list, cause we can only go front to back or back to front.
