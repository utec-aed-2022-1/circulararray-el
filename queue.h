#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> {
private:
    int *array;
    int capacity;
    int size;
public:
    Queue(){
        T *array = nullptr;
        capacity = size = 0;
    }
    Queue(int cap){
        capacity = cap;
        array = new T[capacity];
        size = 0;
    }
    void enqueue(T data){
        push_back(data);
    }

    void dequeue(){
        pop_front();
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