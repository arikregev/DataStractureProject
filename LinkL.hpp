//  Created by ARx & AF.
#pragma once
//#include "main.cpp"
#include "Header.h"
class NodeL {
public:
    int _data;
    NodeL* _next;
public:
    void setData(int data);
    void setNext(NodeL* next);
    NodeL();
    NodeL(int data, NodeL* next);
    ~NodeL();
    const int getData();
    NodeL* operator++();
};
class LinkL : public NodeL{ // Head, Tail
public:
    NodeL* _head;
    //Node* _tail;
    int _numOfNodes;
    LinkL() : _head(NULL), /*_tail(NULL)*/ _numOfNodes(0) {}
    ~LinkL() {
        this->_head = NULL;
    }
    bool isEmpty();
    void Enqueue(int data);
    int Dequeue();
    void printClip();
};
