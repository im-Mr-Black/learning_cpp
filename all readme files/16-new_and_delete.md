# New and Delete Keyword

## SMA vs DMA

- SMA: Static Memore Allocation(iska `static` keyword se koi lena dena nahi hai)
- DMA: Dynamic Memory Allocation

**static memory allocation**, toh ise aise define kar sakte hai, toh jab hum declaration kar rahe hote hai C/CPP me, jaise

```cpp
int x;
float y;
Student s1;
Complex c1;
```

toh iss case me compilation ke waqt hi iss program ko memory kitni memory lagegi woh predict kar li jaati hai, compiler yeh jaan leta hai ki kitti memory ki garaj hai iss program ko run karne ke liye. Yeh jo banai hui space hai ise na toh hum badha sakte hai na hi ghata sakte hai.**isse yeh nahi samajhna hai ki compile hote waqt hi memory allocate ho jaati hai, memory toh tab hi allocate hoti hai jab program run hota hai.**

Aur inn sab variables ki ek life hoti hai, use bhi na hi hum badha sakte hai na hi ghata sakte hai. Jaise kisi function me agar yeh sab variable hai toh woh function khatam hote hi yeh variable bhi clear ho jaate hai, toh ise hum iski alloted life time se pehle khatam nahi kar sakte.

Now coming to **DMA**, SMA me hum variables me flexibiltiy nahi laa paa rahe the but hum DMA ki madad se full flexibility laa sakte hai.

Declaration statements se hum DMA nahi bana sakte usse hum bas SMA hi bana sakte hai.`new` keyword use karke hum CPP me dynamic memory allocation kar sakte hai.

```cpp
int *p = new int;
float *q = new float;
Complex *ptr = new Complex;
```

toh iska syntax aisa hai `new` keyword ke baad likhna hota hai data type phir for example likha hai `new int` toh `int` type ka a variable create ho jaaega jabki jo `p` pointer hai woh SMA ka example hai, toh use bhi memory milegi, yeh compile time pe decide ho chuka hai ki pointer ko kitti memory milegi.Pointer ab uss DMA ko point kar raha hoga.

`new` se bane variable DMA type ka hota hai aur uska koi naam nahi hota hai, uska bas ek address hota hai jo ki pointer se define kiya jaata hai. Pointer jis type ka hota hai usi type ke variable ki value contain karta hai.

Hum, `new` ki help se array bhi bana sakte hai,

```cpp
float *q = new float[5];

int x;
cin >> x;
itn *p = new int[x];
```

hum aisa bhi kar sakte hai ki user se input leke ek array bana sakte hai.

## Delete Keyword

toh jis tareeke se hum `new` keyword use karke dyanmic variable bana sakte hai, usi tareeke se hum woh variable `delete` keyword use karke delete kar sakte hai.

Yaad rahe `delete` keyword se hum bas wahi variable ko delete kar sakte hai jo `new` keyword se bane hai, aur agar hum uss DMA ko delete na kare toh uss variable ki lifetime thoughout the program hoti hai.

```cpp
delete p;       // agar bas variable banaya hai
delete []p;   //agar array banaya hai toh yeh
```

toh syntax aisa hai ki pehle `delete` keyword likhenge phir uske pointer ka naam, agar array banaya hai toh square brackets phir uske pointer kaa naam.
`delete` keyword se pointer `p` delete nahi ho raha hai, balki pointer `p` jise point kar raha hai woh delete ho raha hai.
