//
// Created by 王尚荣 on 2020/10/15.
//

#ifndef AC_AUTOMATION_QUEUE_H
#define AC_AUTOMATION_QUEUE_H
#include <stdio.h>
#include <string.h>
#include "List.h"
/**
 * AC自动机的节点结构
 */
class Node{
public:
    Node(){
        children = new Node* [256];
        for(int i = 0; i < 256; ++i) {
            children[i] = nullptr;
        }
        fail = nullptr;
    }
    ~Node(){
        for(int i = 0; i < 256; ++i)
            delete children[i];
        delete [] children;
    }
    Node** children;
    Node* fail;
    List<char*> outputList;
};

/**
 * 循环队列，用于dfs构建AC自动机的fail域
 */
class queue {
public:
    queue(int n=2048);
    ~queue();
    void push_back(Node* p);
    Node* front();
    Node* back();
    Node* pop_front();
    bool isEmpty();
private:
    int capacity;       // 容量
    int length;         // 当前数组长度
    int head;           // 队列首
    int tail;           // 队列尾
    Node** array;

    void reSize();      // 队列加倍
};


#endif //AC_AUTOMATION_QUEUE_H
