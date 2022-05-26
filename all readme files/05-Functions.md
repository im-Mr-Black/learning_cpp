# Function

- it is a block of code/set of instruction.
- it is used to perform some task
- it is either user defined or pre defined
- predefined functions are declared in header files and defined in library.
- it is a way to achieve modularization.

## definition declaration and call

![Function call, reference, declaration and definition](/all%20readme%20files/images/function%20declaration%2C%20call%20%2C%20definition.png)

## Declaration

- takes nothing, returns nothing
- takes something, return nothing
- takes nothing, returns something
- takes something, return something

## types of formal arguments

- ordinary variable of any type
- pointer variables
- reference variables

## call by value

## Inline function

inline function woh function hai jisme bas inline function likh ke kaam ho jaata hai. Fir jaha jaha woh function call hua hoga wahi pe woh apne apne aap execute ho jaega

Inline is a request not a command
the benefits of speed of inline function reduces as the function grows in size.

- Compiler might ignore the request in some situations.Some of them are:
  - function contains loop,swtich, goto.
  - functions with recursion
  - containing static variable.

```cpp
#include <iostream>

using namespace std;

inline void fun();  //function declaration
int main(){
    cout << "you are in main" << endl;
    fun();          //function call

    return 0;
}
// function definition
void fun(){
    cout << "You are in fun";
}
```

- easy to read
- easy to modify
- avoids rewriting of same code
- easy to debug
- better memory utilization(main adv.)

## Function overloading

- polymorphirm - iska matlab hai ek hi cheez ke multiple interpretations hona aur har interpretations har situation me clear hona
- function overloading isiko achieve ko karne ka ek tareeka hai

- (formal definiton) when one function name is overloaded with different jobs then it is called as function overloading.

- compiler ke bahut sare kaam me se ek bahut important kaam yeh hai ki usko kisi variable ya call ke saath bind kar dena ise hum early binding bhi kehte hai.
- early binding matlab compile time pe hi bind kar dena, bind kar dena matlab jod dena, map kar dena.

### Binding ke 3 rule hote hai

1. exact match - jab given data hamare function call se exactly match kar jaata hai.
2. type promotion - type promote karna matlab char, unsigned char aur short is promoted to an int while float is promoted to double.
3. if no promotion is found, C++ tries to find a match through standard conversion.
