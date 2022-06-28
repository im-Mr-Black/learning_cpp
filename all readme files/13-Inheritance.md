# Inheritance

**encapsulation** yeh kehta hi ki ek object se related uska saari properties ek hi class me honi chahie.

- it is a process of inheriting properties and behaviours of existing class into a new class.
- existing class = old class = parent class = base class
- new class = child class = derived class

syntax

```cpp
#include <iostream>
using namespace std;

class Base_class{
};

class Derived_class: Visibility_mode Base_class{

}
```

for example ab hum ek class banana chahte hai car naam ka toh woh banaenge (usme kuch variables bhi honge aur kuch functions bhi) , ab hame ek class banani hi sportcar ki toh usme car ki toh saari properties hongi hi plus kuch aur new properties add ho jaengi toh instead of writing again we will inherit properties of car class aur apni kuch aur properties add kar denge.

```cpp
#include <iostream>
using namespace std;

class Car{
};

class SportsCar: public Car{
};
```

### Inheritance part 2

- Types of inheritance

  - single inheritance
    - single inheritance woh hota hai jaha ek parent class hoti hai aur ek child class hoti hai.
  - multilevel inheritance
    - transitive relationship hota hai matlab, ek class hai class A woh class B ki parent class hai aur ek class C hai uski parent class hai class B. So, the relation goes like class A -> class B -> class C.
    - we wont say class C ka parent class A, class B hi parent hai class C ki. Class C me class A ke saari properties hai bas!
  - multiple inheritance
    - isme ek class ek se zyaada class me properties inherit karti hai uss case me multiple inheritance bolte hai.
    - jaise ek class hai class B woh inherit kar rahi hai class A1 aur Class A2 dono se, inn dono me apas me koi relation nahi hai .
  - hierarchical inheritance
    - isme ek parent class hai aur uski bohot saari child class hai.
    - jaise ek class hai class A usse class B1 aur class B1 dono properties inherit kar rahi hai.
  - hybrid inheritance.
    - ek se zyaada inheritance ka mixture hota hai hybrid inheritance.

- Visibility mode(access specifiers)
  - private
  - public
  - protected

**Types of users of a class**

- user 1 will create objects of your class.
- user 2 will derive class from your class.

**availability vs accessibility**,
isme antar samajhna bahut hi important hai.
Availability - toh isme yeh kehna chahte hai ki object kaisa bhi private protected or public sabko memory milti hai, yaani woh space lega jab bhi ek object uss class ka create hoga, lekin accessible sirf wahi members honge jo public me banae jaenge.

## Private

- toh ab private members available dono(user 1 and user 2) ko hai jab koi ek object banata hai but accessible dono ko nahi hai.

## Public

- isme user 1 aur user 2 dono hi access kar sakte hai.

## Protected

- isme user 2 access kar sakta hai but user 1 nahi kar sakta.
  > in the below given image first topmost part of the block represents private , middle one represents protected and the bottom one represents public.

![Visibility Modes](/all%20readme%20files/images/visibility_modes.PNG)

upar wali photo availability ki nahi balki accessibility ki photo hai.

**how to read** toh jab class B class A se as `private` inherit karega tab class A ke protected aur public member class B me as private members inherit honge, like that other 2.

### inheritance part 3

## is-a relationship

**is a** relationship is always implemented as a public inheritance.

**why?** kyuki hame parent class ki saari properties child class me chahie.

**when to use protected and private** jab "is a" relationship nahi hota tab either private or protected use kiya jaata hai(according to the needs).
