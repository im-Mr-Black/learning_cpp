# Introduction

---

It is a increment in C language.

## comparision between C and CPP

- cpp is a super set of C language.
- cpp can use existing C software libraries.
- C follows top to down approach of programming
  top down programming means - how do you approach the programming,

## object oriented programming

- there are 5 key principles of OOPs, these are:

  - encapsulation
  - data hiding
  - abstraction
  - polymorphism
  - inheritance

- Classes and object

  - class is a blueprint of an object(naksha of the makaan, kaagaz pe just info about this thing)
  - object vs variable
    -object is a block inside which there exist many variables.(bada sa block jiske ander kaafi saare variable exist karte hai)
    - variable 1 block hai jisme sirf 1 data store hota hai
  - class is a description of object's property set and set of properties.

- Software development in Cpp
  - to run a software we just have to make an exe file but the thing is it will run on just one OS, and that means we have to make executable files for each and every OS. So instead of doing that we make a code file(eg. sum.cpp) then we need a preprocessor, this will merge content of header files(files that start with '#') with our code file after merging a new file (eg. sum.i) is created in RAM then this sum.i is read by compiler and this will translate the file according to OS (creating sum.obj). Now there is still some content that is not readable by the OS and that info in contained in the library files, so a linker software is used to link library files with sum.obj to create sum.exe that is readable by the OS.
    ![software creation](/all%20readme%20files/images/software_creation.png)
