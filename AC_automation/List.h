//
// Created by 王尚荣 on 2020/10/19.
//

#ifndef AC_AUTOMATION_LIST_H
#define AC_AUTOMATION_LIST_H
#include <iostream>
/**
 * 可变长数组List类实现
 * @tparam T 类型
 */
template<class T>
class List {
public:
    List(int n=4);
    void append(T value);
    bool isEmpty();
    int size();
    T& operator[](int n);
    ~List();
private:
    int capacity;       // 容量
    int length;         // 当前数组长度
    T*  array;
private:
    void reSize();
};

template<class T>
List<T>::List(int n) {
    array = new T[n];
    capacity = n;
    length = 0;
}

template<class T>
void List<T>::reSize() {
    T* p = new T[capacity * 2];
    for(int i = 0; i < length; i++)
        p[i] = array[i];
    capacity *= 2;
    delete[] array;
    array = p;
}

template<class T>
void List<T>::append(T value) {
    if(length == capacity)
        reSize();
    array[length++] = value;
}

template<class T>
List<T>::~List() {
    delete[] array;
}

template<class T>
bool List<T>::isEmpty() {
    return length == 0;
}

template<class T>
int List<T>::size() {
    return length;
}

template<class T>
T &List<T>::operator[](int n) {
    return array[n];
}


#endif //AC_AUTOMATION_LIST_H
