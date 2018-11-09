//  Created by ARx & AF.
#include "LinkL.hpp"

//########################NodeStart###############################
void LinkL::NodeL::setData(int data) { this->_data = data; }
void LinkL::NodeL::setNext(NodeL* next) { this->_next = next; }
LinkL::NodeL::NodeL() :_data(0), _next(NULL) {}
LinkL::NodeL::NodeL(int data, NodeL* next) {
    this->_data = data;
    this->_next = next;
}
LinkL::NodeL::~NodeL() {this->_next = NULL; }
const int LinkL::NodeL::getData() { return this->_data; }
LinkL::NodeL* LinkL::NodeL::operator++() {
    return this->_next;
}
//#########################NodeEnd################################
//#######################LinkLStart###############################
bool LinkL::isEmpty() {
    if (_head == NULL)
        return true;
    return false;
}
void LinkL::Enqueue(int data) {
    // first check if it's empty and initzilltion the new data
    if (this->isEmpty())
    {
        this->_head = new NodeL;// make new alloction memory of the node
        _head->_data = data;// initzillation the data member of the new node
        this->_head->setNext(this->_head);
        this->_numOfNodes++;
        return;
    }
    // to put the data in order from big to small
    // the head point the max number
    // the tail point the min number
    if (data > this->_head->_data)
    {
        // need to put the new node in the first place in list
        // use temp node for save the pointers
        // move all of the pointers next
        NodeL *temp = new NodeL;//  new Node; // need to do a memory allocation for new struc
        temp->_data = this->_head->_data; // copy the data from the first one to the new one
        this->_head->_data = data; // updated the new data for the max (head)
        temp->_next = _head->_next;
        _head->_next = temp; // head next point on temp //
        // temp next get tail and organized the full list
        this->_numOfNodes++;
        return;
    }
    NodeL *p = this->_head;
    int i = 0;
    while (i <= this->_numOfNodes) {
        if (data < p->getData() && data > p->_next->getData()) {// if the data we get big we need to put him ther
            NodeL *n = new NodeL;
            n->setData(data);
            n->_next = p->_next; // NEXT
            p->_next = n;
            this->_numOfNodes++;
            break; // when you place the data in the correct place get out from the loop
        }
        if (data == p->getData()){
            NodeL* n = new NodeL;
            n->setData(data);
            n->_next = p->_next;
            p->_next = n;
            this->_numOfNodes++;
            return;
        }
        if (p->_next == this->_head) {
            NodeL* n = new NodeL;
            n->setData(data);
            n->_next = this->_head;
            p->_next = n;
            //this->_tail = n;
            this->_numOfNodes++;
            break;
        }
        else {
            p = p->_next;
            i++;
        }
    }
}
int LinkL::Dequeue() {
    int data = this->_head->getData();
    if (this->_head == NULL)
        return -1;
    if (this->_numOfNodes == 1) {
        delete this->_head;
        this->_head = NULL;
        this->_numOfNodes--;
        cout <<"Number: " << data << " Dequeued from LinkList" << endl;
        return data;
    }
    NodeL* nxt = this->_head->_next;
    delete this->_head;
    this->_head = nxt;
    NodeL* temptail = this->_head;
    for(int i = 0; i < this->_numOfNodes - 2; i++)
        temptail = temptail->_next;
    temptail->_next = this->_head;
    this->_numOfNodes--;
    cout <<"Number: " << data << " Dequeued from LinkList" << endl;
    return data;
}
//########################LinkLEnd################################
