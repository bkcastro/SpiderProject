//
// Created by Brandon Castro on 6/5/21.
//

#include "States.h"

States::States()
{
    for(int i=0; i<LAST; i++)
        objectStates.push_back(false);
}
bool States::checkState(states state)
{
    return objectStates[state];
}
void States::enableState(states state)
{
    objectStates[state] = true;
}
void States::disableState(states state)
{
    objectStates[state] = false;
}