//
//  SidePile.cpp
//  Testing
//
//  Created by Eder Aguilar on 10/31/23.
//

#include <stdio.h>
#include "SidePile.h"

SidePile::SidePile() {
    arr = new int[5]; //Max card limit of 5;
    stackSize = 5; //current size of stack
    top = -1;
}

SidePile::~SidePile() {
    delete [] arr;
}

bool SidePile::isFull() const {
    bool status;
    
    if(top == stackSize - 1) {
        status = true;
    } else {
        status = false;
    }
    return status;
}

bool SidePile::isEmpty() const {
    bool status;
    
    if(top == -1)
        status = true;
    else
        status = false;
    
    return status;
}

void SidePile::push(int card) {
    if(isFull()) {
        string error = "Error! The side pile is full!";
        throw error;
    } else {
        top++;
        arr[top] = card;
    }
}

int SidePile::pop() {
    if(isEmpty()) {
        string error = "Error! the side pile is empty!";
        throw error;
    }
    int card = arr[top];
    top--;
    return card;
}

int SidePile::getSPLength() {
    if(top == -1) {
        return 0;
    } else {
        return top;
    }
}
