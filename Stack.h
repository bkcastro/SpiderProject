//
// Created by Brandon Castro on 6/8/21.
//

#ifndef SPIDERPROJECT_STACK_H
#define SPIDERPROJECT_STACK_H
#include "StackFrame.h"

class Stack {
public:
    Stack();
    ~Stack();

    void push(Card card);
    Card peek();
    Card pop();
    bool empty() const;

private:
    StackFramePtr top;
};


#endif //SPIDERPROJECT_STACK_H
