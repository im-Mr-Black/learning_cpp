# Input and output

## output instruction

- in C, standard o/p device is monitor and printf() is used to send data or message to monitor.
- printf() is a predefined function.
- cout is an object(prdefined)
- << is called insertion operator.

```C
printf('my name is shubham');
printf('sum of %d and %d is %d', a,b,c);
```

```c++
cout << 'my name is shubham'
cout << 'sum of' << a << 'and '<< b << 'is '<< c;
```

- here you don't have to care about the format specifier(%d %f yeh sab). Here you directly name the variable you want to print.

## input instruction

- in C we use scanf()
- scanf() is a predefined function

- cin is predefined object
- '>>' is extraction operator.

## header files

- iostream. is a header files , cout cin and << and >> are declared over here, these contains declaration of idenfiers
- identifiers can be function names variables, objects macros etc.

- endl is a manipulator and it is declared in
