//
// Created by Brandon Castro on 6/8/21.
//

#ifndef SPIDERPROJECT_STACKFRAME_H
#define SPIDERPROJECT_STACKFRAME_H
#include "Card.h"

struct StackFrame {
    Card card;
    StackFrame *link;
};
typedef StackFrame* StackFramePtr;


#endif //SPIDERPROJECT_STACKFRAME_H
