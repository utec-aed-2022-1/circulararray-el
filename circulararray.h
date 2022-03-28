#include <iostream>
#include <string>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;

public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void clear();
    T &operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep = " ");

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = "";
    for (int i = 0; i < size(); i++)
        result += std::to_string(array[i]) + sep;
    return result;
}

template <class T>
void CircularArray<T>::push_front(T data)
{
    if (front < 0)
        front = back = 0;
    for (int i = back; i >= 0; i--)
    {
        array[i + 1] = array[i];
    }
    ++back;
    array[front] = data;
}

template <class T>
void CircularArray<T>::push_back(T data)
{
    if (back < 0)
    {
        front = back = 0;
        array[back] = data;
    }
    else
        array[++back] = data;
}

template <class T>
void CircularArray<T>::insert(T data, int pos)
{
}

template <class T>
T CircularArray<T>::pop_front()
{
    for (int i = 1; i < back; i++)
    {
        array[i - 1] = array[i];
    }
    --back;
    return array[front];
}

template <class T>
T CircularArray<T>::pop_back()
{
    T *temp = new T;
    *temp = array[back];
    if (back == 0)
        back = capacity;
    else
        back--;
    return *temp;
}

template <class T>
bool CircularArray<T>::is_full()
{
    return (back == capacity - 1) ? true : false;
}

template <class T>
bool CircularArray<T>::is_empty()
{
    return (front < 0) ? true : false;
}

template <class T>
int CircularArray<T>::size()
{
    return front > back ? (capacity - front + back + 1) : (back - front + 1);
}

template <class T>
void CircularArray<T>::clear()
{
}

template <class T>
T &CircularArray<T>::operator[](int)
{
}

template <class T>
void CircularArray<T>::sort()
{
    for (int i = 0; i < size()-1; i++) {   
     

    for (int j = 0; j < size()-i-1; j++){
        if (array[j] > array[j+1]){
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
      }
      }
      }
}

template <class T>
bool CircularArray<T>::is_sorted()
{
    for (int i = 1; i < back; i++)
    {
        if (array[i - 1] > array[i])
            return false;
    }

    return true;
}

template <class T>
void CircularArray<T>::reverse()
{
    for (int low = 0, high = size() - 1; low < high; low++, high--) {
        T temp;
        temp = array[low];
        array[low] = array[high];
        array[high] = temp;
    }
}