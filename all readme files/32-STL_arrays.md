# Arrays

- array is a linear collection of similar elements.
- Array containers in STL provides us the implementation of static array.
- use header array

  - `#include <array>`

- `array <m , n> object;`
  - here `m` is the data type of each element of the array.
  - `n` is the size of array that we are going to make.

This is how we are gonna make an array.

```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
    array<int, 5> data_array;
}
```

## Assignment of values during declaration

- we can also initialize at the time of declaration.

```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
    array<int, 5> data_array = {1,2,3,4};
}
```

- accha yeh bilkul zaruri nahi hai ki aap ne agar 5 ke size ka array banaya hai toh aapko 5 values deni hi hogi, aap kam bhi values daal sakte hai.

## Member Functions

- Following are the important and most used member functions of array template:
  - at
  - [] operator
  - front()
  - back()
  - fill()
  - swap()
  - size()
  - begin()
  - end()

---

# at() function

- This method returns value in the array at the given range.
- If the given range is greate that the array size, out_of_range exeption is thrown.

```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
    array<int, 5> data_array = {1,2,3,4};
    cout << data_array.at(2);
}
```

This will o/p `3`. Now what if we give index out of the range.

```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
    array<int, 5> data_array = {1,2,3,4};
    cout << data_array.at(5);
}
```

This will throw an error. The error message will be `terminate called after throwing an instance of 'std::out_of_range' what(): array::at: __n (which is 5) >= _Nm (which is 5)`

## [] operator

- the use of operator [] is same as it was for normal arrays.agar nahi samjha toh neeche ek example se dekh sakte hai

```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
    array<int, 5> data_array = {1,2,3,4};
    cout << data_array[2];
}
```

toh yeh `3` o/p me dega. What if we give index out of range. Is case me error message nahi aaega, iss case me ek garbage value throw kar di jaegi compiler ke through.

## front() and back() functions

- front() method returns the first element in the array.
- back() method returns the last element in the array.

```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
    array<int, 5> data_array = {1,2,3,4};
    cout <<"front element of the array " << data_array.front() << endl;
    cout <<"last element of the array " << data_array.back() << endl;
}
```

toh hum dekh ke bata sakte hai ki front() function use karne pe hume `1` mil jaega but agar hum dhyaan se dekhe toh humne array 5 length ka banaya hai but element toh 4 hi hai toh back method me kya milga? well, agar hum iss condtion me back method use karenge toh hume `0`(zero) milega.(yaani agar hum array ko fully fill nahi karte hai toh compiler use zero se fill kar deta hai).

## fill() function

- this method assigns the given value to every element of the array.(hum poore array me ek jaisi value fill kar paenge).

```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
    array<int, 7> data_array = {1,2,3,4};
    data_array.fill(5);
    for (int i = 0; i < 7; i++){
        cout << data_array.at(i) << " ";
    }
}
```

iska o/p 7 times 5 likh ke aaega.

## swap() function

- This method swaps the component of two arrays of same type and same size.
- It swaps index wise, thus element of index `i` of first array will be swapped with the element of index `i` of the second array.
- SYNTAX:
  - `first_array.swap(second_array)`

```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
    array<int, 7> data_array = {1,2,3,4};
    array<int, 7> second_array;
    second_array.fill(69);
    data_array.swap(second_array);

    for (int i = 0; i < 7; i++){
        cout << data_array.at(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < 7; i++){
        cout << second_array.at(i) << " ";
    }
}
```

Toh isse data_array ka value second_array me chala jaega aur second wale ka data me aa jaega.

## size() function

- This method returns the number of element present in the array.

```cpp
#include <iostream>
#include <array>
using namespace std;

int main(){
    array<int, 7> data_array = {1,2,3,4};
    cout << data_array.size();
}
```

toh iss function ke through hum array ka size pata kar sakte hai, but agar hum dhyaan se dekhe toh upar wale example me humse size 7 diya hai but number of items 4 hai toh o/p kya hoga. Well o/p 7 hi aaega irrespective of the number of the elements present in the array.

## begin() and end()

(yeh hum iterators padhte waqt jaada details me padhenge)

- begin() method returns the iterator pointing to the first element of the array.
- end() method returns an iterator pointing to an element next to the last element in the array.
