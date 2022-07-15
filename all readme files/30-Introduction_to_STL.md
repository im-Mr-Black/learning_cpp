# Introduction to STL

## STL

- STL is standard template library.
- it it a powerful set of CPP template class.

- At the core of the CPP standard template library are following three well-structured components:
  - Containers
  - Algorithms
  - Iterators

## Containers

- Containers are used to manage collections of object of a certain kind.
- Container library in STL provide containers that are used to create data structures like arrays, linked list, trees etc.
- These containers are generic, they can hold elements of any data types.

- for example, vectors can be used for creating dynamic arrays of char, int, float and other types.

## Algorithms

- Algorithms act on containers. They provide the means by which you will perform initialization, sorting, searching, and transforming of the contents of containers.
- Algorithms library contains built in functions that perform complex algorithms on the data structures.

- for example, one can reverse a range with reverse() function, sort a range with sort() function, search in range with binary_search() and so on.

- Algorithm library provides abstraction, i.e. you don't necessarily need to know how thee algorithm works.

# Iterators

- Iterators are used to step through the elements of collections of objects. These collections may be constainers or subsets of containers.
- Iterators in STL are used to point to the containers.
- Iterators actually acts as a bridge between containers and algorithms.

- for example, sort() algorithm have two parameters, starting iterator and ending iterator, now sort() compare the elements pointed by each of these iterators and arrange them in sorted order, thus it does not matter what is the type of the container and same sort() can be used on different types of container.
