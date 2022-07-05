#include <iostream>
using namespace std;

class ArrayList{
    private:
    struct ControBlock{
        int capacity;
        int *arr_ptr;
    };
    ControBlock *s;
    public:
        ArrayList(int capacity){
            s = new ControBlock;
            s->capacity = capacity;
            s->arr_ptr = new int[s->capacity];
        }
        void addElement(int index , int data){
            if (index >= 0 && index < s->capacity){
                s->arr_ptr[index] = data;
            } else{
                cout << "\nArray index is not valid." << endl;
            }
        }
        int viewElement(int index ,int &data){
            if(index >= 0 && index < s->capacity){
                data = s->arr_ptr[index];
            } else{
                cout << "\nArray is not valid." << endl;
            }
        }
        int viewList(){
            int i;
            for (i = 0; i < s->capacity;i++){
                cout << " " << s->arr_ptr[i];
            }
        }
};

int main(){
    int s;
    ArrayList list1(4);
    list1.addElement(0, 31);
    list1.addElement(1, 41);
    list1.addElement(2, 51);
    list1.viewElement(1, s);
    list1.viewList();
    cout <<"\n" <<s;
}