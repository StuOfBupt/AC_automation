//
// Created by 王尚荣 on 2020/10/15.
//

#include "queue.h"

queue::queue(int n) {
    array = new Node*[n];
    capacity = n;
    head = 0;
    tail = -1;
    length = 0;
}

queue::~queue() {
    delete[] array;
}

void queue::push_back(Node *p) {
    if(length == capacity)
        reSize();
    tail = (tail + 1) % capacity;
    array[tail] = p;
    length++;
}

Node *queue::front() {
    if (length == 0)
        return nullptr;
    return array[head];
}

Node *queue::back() {
    if(length == 0)
        return nullptr;
    return array[tail];
}

Node *queue::pop_front() {
    if(length == 0)
        return nullptr;
    length--;
    Node* first = array[head];
    head = (head + 1) % capacity;
    return first;
}

void queue::reSize() {
    Node** p = new Node*[capacity * 2];
    int pos = head;
    for(int i = 0; i < length; i++){
        p[i] = array[pos];
        pos = (pos + 1) % capacity;
    }
    delete[] array;
    array = p;
    capacity *= 2;
    head = 0;
    tail = length - 1;
}

bool queue::isEmpty() {
    return length == 0;
}
