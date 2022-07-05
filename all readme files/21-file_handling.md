# File Handling

- data persistence, streams,

- Stream
  - output stream
  - input stream

![Streams](/all%20readme%20files/images/streams.png)

yeh upar wali jo photo hai usme arrow ka matlab hai class ke beeche me relation, jaise `ios` ki 2 child class hai `istream` aur `ostream` aur woh dono merge hoti hai ek class me `iostream` me toh `iostream` dono ki child class hai. Now, abhi tak jo hum `cout` aur `cin` use kar rahe the woh bhi inhi me thi, jaise `cin` `istream_wihtassign` ka ek bana banaya function hai jise humne nahi banaya similarly `cout` `ostream_withassign` ka ek bana banaya function/operator hai, aur jaise hum extraction operator(`>>`) use karte hai `cin` ke saath me woh `istream` me hai jo ki uska parent class hai, toh yeh operator usne apni parent class se inherit kar liya hai.

Now, in case of file handling, hume `cout` ye `cin` jaise bane banae function nahi milenge, hume yeh khud banane padenge aur phir unpe operations karna hoga.

hum `fstream` library ko import karenge aur `ofstream` ka object banenge for writing and `ifstream` ka object for reading.

## Writing Data onto a file

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream fout;
    fout.open("myfile.dat ");
    fout << "hello";
    fout.close();
    return 0;
}
```

`ofstream fout;` toh ek object create kiya humne ofstream` ka. yeh hai hamari output stream ki line, iske through hamara data jo bhi file hai usme jaega from the program file.But abhi tak toh humne woh file open ya specify hi nahi ki jise me hamari yeh output stream jaegi.

`fout.open("myfile.dat ");` toh yeh hai woh function jo hamare liye woh file open kar dega jisme hume hamare program se data utha ke ke file me store karna hai. Toh `.open()` function hamare liye woh file open kar dega, toh agar hum directly bas file ka naam likhte hai toh yeh function uss directory me file ko search karega jisme hamara program run ho raha hai, aur agar woh file exist nahi karti hai uss directory me toh yeh function woh file ko create bhi kar dega hamare liye(how sweet XD).

`fout << "hello";` toh iss function ka use karke hum compiler ko yeh bata rahe hai ki jo file abhi open ki hai humne usme hume hello string ko push/save karna hai. Accha jo file humne open ki thi use close karna bhi zaruri hai kyuki agar aap use program me run karke chodd degne toh woh file pe jo write hua hai woh sirf RAM me reh jaega aur jabtak woh close nahi hoga woh HDD/SSD me store nahi hoga. Yaani uski ek copy jo RAM me push hui thi for the program to run usi me yeh data reh jaega.
`fout.close()` ka use karke hum file ko close kar sakte hai.

Toh `ofstream` ka object tab banaenge jab hume data output karna hoga kisi file me aur `ifstream` ka object hum tab banaenge jab hume data ko input karna hoga kisi file se.

### File handling part 2

## Reading data from a file

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin;
    char ch;
    fin.open("myfile.dat");
    fin >> ch;

    while(!fin.eof()){
        cout << ch;
        fin >> ch;
    }
    fin.close();
}
```

toh hum dekh sakte hai ki hume iss baar file ko read karna hai use output karna hai screen pe.

Toh hum `ifstream` ka object banate hai `fin` fir hum humari file open karte hai `myfile.dat` now using `fin >> ch;` hum file se data read kar rahe hai jo ki myfile.dat me pada hua hai. Now, the thing is `ch` toh bas ek character hi store kar sakte hai toh hum ek while loop lagate hai toh read the whole file.

Toh while loop me humne ek condition likhi hai `!fin.eof()`, toh ise samjhte hai, `eof` function ka matlab hai **end of file**, toh yeh 1 pass karte hai when the file ends and 0 jab tak file me data exist karta hai, but jo while loop hai woh toh 0 pe loop band kar dega toh humne negation ka sign laga diya taaki sab ulta ho jae aur hamara while loop aaram se apna operation perform kar sake.

toh while loop me phir kuch nahi hum ek ek character ko print kar rahe hai screen pe. `cout` kar rahe hai `ch` ke andar pade character ko aur usi ke just baad `ch` me ek character input le rahe hai using `fin`.

---

Now what if we write "hello students." inside, myfile.dat file, well we will get `hellostudents.` so we get everything except the space. Toh problem aati hai extraction operator(`>>`) me woh space, tab(4 times space) aur new line ko data seperator maanta hai, inhe aisa special character maanta hai jise use ignore karna sahi lagta hai, toh isliye hamare given text me koi space nahi tha. Toh ab kya kare hum iske liye.

Toh hum use karenge `get` function ko jo ki same kaam karenge aur woh space ko special character bhi nahi maanta toh hume `hello students.` hi wapas se milega.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin;
    char ch;
    fin.open("myfile.dat");
    ch = fin.get();

    while(!fin.eof()){
        cout << ch;
        ch = fin.get();
    }
    fin.close();
}
```

### file handling part 3

## File Opening Modes

| Command     | Usage        | Meaning                                                                                                                                                                                                                              |
| ----------- | ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| ios::in     | input/read   | iska matlab yeh hai ki aap file open kar rahe hai file ko read karne ke liye.                                                                                                                                                        |
| ios::out    | output/write | iska matlab yeh hai ki aap file open kar rahe hai file ko write karne ke liye. But yaad rahe jab bhi aap iska use karenge for editing your file, yeh purana content mita ke sab nae se likhega. Toh aap apna pura content kho denge. |
| ios::app    | append       | yeh mode hum tab use karte hai jab hum chahte hai ki purana content erase na ho aur naya content uska aage se jud jae toh hum append mode ka use karte hai.                                                                          |
| ios::ate    | upate        | yeh mode hum tab use karte hai jab hume                                                                                                                                                                                              |
| ios::binary | binary       | iske baare me abhi kuch nahi                                                                                                                                                                                                         |

---

```cpp
#include <iostream>
#include <fstream>
using namespace std;

void main(){
    ofstream fout;
    fout.open("myfile1.dat" , ios::out); //default argument is ios::out
}
```

Toh aise hum as an argument pass karte hai, mode jisme hume yeh file open karni hai. Hum ek se zyaada mode me bhi open kar sakte hai apni file ko.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream fout;
    fout.open("myfile1.dat" , ios::app | ios::binary | ios::in);
    fout.close();
}
```

iss tareeke se hum more than one mode me apni file ko open kar sakte hai. But, there is some problem in the above given code. Well, you can't open a file in input mode, reason being the object belongs to `ofstream` and it is used for writing while `ios::in` is function that is relevant to the objects that belongs to `ifstream`.

## Text mode vs binary mode

toh jab bhi aap `ios::binary` nahi likhte hai file text mode me open ho jaati hai.

Now text mode me jab bhi file open hoti hai, iska matlab yeh hota hai ki jab bhi woh file ko input ya output kar raha hoga tab woh special characters ko as special characters dekhega aur unke meaning ke hisab se woh write/read karega. Wahi agar file binary mode me open hoti hai toh woh har cheez ko as a text dekhega aur unme use hue special characters ko as it is read/write kar dega.

For example, jab hum likhe
`fout << "my name is \nShubham";`, isme kya hoga, jab text mode me file open hogi tab `\n` ko special character ki tarah dekha jaega aur Shubham new line me print/write hoga, wahi binary mode me jab yeh print/write hoga toh `\n` as a text dekha jaega toh yeh pura string ek hi line me write/print ho jaega along with `\n`
