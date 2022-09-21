//
// Created by Brandon Castro on 6/8/21.
//

#include "Stack.h"

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {

}

void Stack::push(Card card) {

    StackFramePtr temp;
    temp = new StackFrame;
    temp->card = card;

    temp->link = top;
    top = temp;
}

Card Stack::peek()
{
    if (!empty())
    {
        return top->card;
    }
    else
    {
        std::exit(1);
    }
}

Card Stack::pop()
{
    if (top != nullptr)
    {
        StackFramePtr temp;
        Card card;
        temp = top;
        top = top->link;
        card = temp->card;
        temp->link = nullptr;
        delete temp;
        return card;
    }
    else
    {
        std::exit(1);
    }
}

bool Stack::empty() const {
    return top == nullptr;
}