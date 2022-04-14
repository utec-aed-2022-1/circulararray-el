#include "circulararray.h"
#include <functional>
using namespace std;

template <typename T>
class StackArray : public CircularArray<T> {
private:
    int *array;
    int capacity;
    int size;
public:
    Stack(){
        T *array = nullptr;
        capacity = size = 0;
    }
    Stack(int cap){
        capacity = cap;
        array = new T[capacity];
        size = 0;
    }

    void push(T data){
        push_back(data);
    }
    void pop(){
        pop_back();
    }

    void display(){
        for(int i = 0; i<size; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }

    int size(){
        size();
    }

};