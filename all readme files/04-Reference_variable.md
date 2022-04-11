# Reference Variable

- har vairalbe ka ek address hota hai
- pointer variable - not a normal variable, this variable contains the address of some other variable.
-

## Reference variable

- this is neither a normal variable, nor a pointer variable
- `int &y = x` this is how we denote a reference variable, also this variable need to be assigned to a variable that is already defined i.e. `x` here should be initialised before
- now what this means is, `y` is taking reference from `x`, what reference means is `y` is gonna take address of `x`, now this seems similar to pointer. The difference is the context, these are used with different context.
- for eg. if you write `y++` this will increment the value of `x` not `y`
- in another word `y` is just another name for `x`.

- reference variable is an internal pointer.
- reference variable must be initialized during declaration.
- It can be initialized with already declared variables.
- Reference variable cann't be updated.
