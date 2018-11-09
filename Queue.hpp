//  Created by ARx & AF.
#pragma once
#include "Header.h"
#include "Tree.hpp"
#include "LinkL.hpp"

class Queue: public Tree, public LinkL {
public:
    void Enqueue(int data){
        this->Tree::Enqueue(data);
        this->LinkL::Enqueue(data);
    }
    int Dequeue(){
        int max = this->FindMax();
        this->Tree::Dequeue(max);
        this->LinkL::Dequeue();
        return max;
    }
    int getRand(){
        mt19937 rng;
        rng.seed(random_device()());
        uniform_int_distribution<mt19937::result_type> dist(1, 1000); // distribution in range [1, 6]
        //cout << dist(rng) << endl;
        return dist(rng);
    }
};
