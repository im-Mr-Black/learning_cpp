# Tuple

- Tuple just like pair, we can pair two heterogenous objects, in tuple we can pair multiple objects.
- toh jab bhi hume 2 ka pair banana hai tab hum pair ka use karte hai, but jab hume 2 se zyada ka pair banana hota hai tab hum tuple ka use karte hai.

## creating and inserting values in tuple

- just like pair we can create and insert values in tuple.
- for inserting values in tuple we have to use `make_tuple()` function.

```cpp
#include <iostream>
#include <tuple>
using namespace std;

int main(){
    // creating a tuple
    tuple<string, int, int> t1;

    // inserting values in tuple
    t1 = make_tuple("shubham", 35, 125);
}
```

## accessing values in tuple

so, you can access values inside the tuple using `get` function.

SYNTAX
`get<position_value_in_tuple>(name_of_tuple)`

```cpp
#include <iostream>
#include <tuple>
using namespace std;

int main(){
    // creating a tuple
    tuple<string, int, int> t1;

    // inserting values in tuple
    t1 = make_tuple("shubham", 35, 125);

    // accessing values in a tuple
    cout << get<0>(t1);  // this will return "shubham"
}
```

## Use of comparision operator

So, we can use comparision operator to compare the two objects in the pair.

- `==`
- `!= `
- `< `
- `>`
- `<=`
- `>=`
