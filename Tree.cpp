//  Created by ARx & AF.
#include "Tree.hpp"

bool Tree::isEmpty(){ //if True father = root
    return (this->_root == NULL);
}
bool Tree::checkSide(Node* side){
    return (side!=NULL);
}
void Tree::Enqueue(int data){
    if(isEmpty()){
        this->_root = new Node;
        this->_runner = this->_root;
        this->_root->_data = data;
        return;
    }
    Node* temp = NULL;
    this->_runner = this->_root;
    while(this->_runner != NULL){
        if(data <= this->_runner->_data){
            temp = this->_runner;
            this->_runner = this->_runner->_LS;
        }
        else{
            temp = this->_runner;
            this->_runner = this->_runner->_RS;
        }
    }
    Node* newL = new Node(temp,data);
    if(newL->_data > temp->_data)
        temp->_RS = newL;
    else
        temp->_LS = newL;
    this->_runner = NULL;
    temp=NULL;
    delete temp;
}
int Tree::Dequeue(int data){ //Receives data to find & delete
    if(this->_root->_data == data && this->_root->_RS == NULL){
        int num = this->_root->_data;
        Node* temp = this->_root;
        this->_root = temp->_LS;
        if(temp->_LS != NULL)
            temp->_LS->_UP = NULL;
        temp->_LS = NULL;
        delete temp;
        cout <<"Number: " << num << " Dequeued from Tree" << endl;
        return num;
    }
    this->_runner = this->_root;
    while(this->_runner->_data != data){
        if(this->_runner->_data < data)
            this->_runner = this->_runner->_RS;
        else if(this->_runner->_data >= data)
            this->_runner = this->_runner->_LS;
        else return -1; //Max num not found.
    }
    if(this->_runner->_LS == NULL && this->_runner->_RS == NULL){ // probably leaf
        int num = this->_runner->_data;
        if(this->_runner->_UP->_RS == this->_runner)
            this->_runner->_UP->_RS = NULL;
        if(this->_runner->_UP->_LS == this->_runner)
            this->_runner->_UP->_LS = NULL;
        delete this->_runner;
        cout <<"Number: " << num << " Dequeued from Tree" << endl;
        return num;
    }
    if(this->_runner->_RS == NULL && this->_runner->_LS != NULL){
        int num = this->_runner->_data;
        this->_runner->_UP->_RS = this->_runner->_LS;
        Node* temp = this->_runner->_UP;
        this->_runner->_LS->_UP = temp;
        delete this->_runner;
        cout <<"Number: " << num << " Dequeued from Tree" << endl;
        return num;
        }
    return 0;
}
int Tree::FindMax(){
    this->_runner = this->_root;
    if(this->_runner->_RS == NULL)
        return this->_runner->_data;
    while(this->_runner->_RS !=NULL)
        this->_runner = this->_runner->_RS;
    return this->_runner->_data;
}



