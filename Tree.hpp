//  Created by ARx & AF.

#pragma once
#include "Header.h"

class Node{
public:
    int _data;
    Node* _RS;
    Node* _LS;
    Node* _UP;
    Node(){
        this->_RS = NULL;
        this->_LS = NULL;
        this->_UP = NULL;
        this->_data = 0;
    }
    Node(Node* UP,int data){//CCTOR that recieves the parent and the data value.
        this->_RS = NULL;
        this->_LS = NULL;
        this->_UP = UP;
        this->_data = data;
    }
    ~Node(){
        this->_UP = NULL;
        this->_LS = NULL;
        this->_RS = NULL;
        this->_data = 0;
    }
};

class Tree: public Node{
public:
    Node* _root;
    Node* _runner;
    Tree() {
        this->_root = NULL;
        this->_runner = NULL;
    }
    ~Tree(){
        this->Node::~Node();
    }
    bool isEmpty();
    bool checkSide(Node* side);
    void Enqueue(int data);
    int Dequeue(int data);
    int FindMax();
};
