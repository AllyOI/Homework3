//
//  SidePile.h
//  Testing
//
//  Created by Eder Aguilar on 10/30/23.
//

#ifndef SidePile_h
#define SidePile_h
#include <iostream>

using namespace std;

class SidePile
{
private:
    int* arr; //pointer to array
    int stackSize; //stack size
    int top; //indicates top of stack
    
public:
    SidePile();
    ~SidePile();
    
    int pop(); //pop -- drawSP will call this
    void push(int); //push -- addSP will call this
    bool isFull() const;
    bool isEmpty() const;
    int getSPLength();
};



#endif /* SidePile_h */
