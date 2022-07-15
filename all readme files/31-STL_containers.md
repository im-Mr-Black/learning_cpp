# STL Containers

- Container library is a collection of classes.
- The containers are implemented as generic class template.
- Containers help us to implement and replicate simple and complex data structures very easily like arrays, list, trees, associative arrays and many more.
- Containers can be used to hold different kind of objects.

## Common containers

- vector: replicates array
- queue: replicates queues
- stack: replicates stack
- priority_queue: replicates heaps
- list: replicates linked list
- set: replicates trees
- map: associative arrays

## Classification of Containers

- Sequence Containers: like arrays, linked list, etc.
  - linear data structure, matlab data linearly data store hota hai, ek ke baad ek.
  - inka ek position number hota hai, ek order number hota hai, ek sequence hota hai.
- Associative Containers: sorted Data Structure like map , set , etc.
- Unordered Associative Containers: unsorted data structures
- Containers Adapters: Interfaces to sequence containers.

## How to use a container Library?

- When we use containers to implement linked list we just have to include the list header file and use list constructor to initialize the list

```cpp
#include <iostream>
#include <list>

int main(){
    list <int> mylist;
}
```

- toh abhi tak hum bas iostream ko include karte the but jab list ka use karna hai hume tab hume `list` naam ka header file bhi include karna hoga. Toh list class ka object banane ke liye hume list header file ko import karna hoga.
- Toh hum template se ise relate kar sakte hai, iss case me hume list banani hai aur humne angular bracket me `int` likha hai iska matlab yeh hai ki hum integer ki list banana chahte hai.
