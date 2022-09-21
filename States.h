//
// Created by Brandon Castro on 6/5/21.
//

#ifndef SPIDERPROJECT_STATES_H
#define SPIDERPROJECT_STATES_H
#include <vector>

class States
{
private:
    std::vector<bool> objectStates;
public:
    States();
    enum states {HOVERED, NORMAL, HIDDEN, FADE, LAST};
    bool checkState(states state);
    void enableState(states state);
    void disableState(states state);

};



#endif //SPIDERPROJECT_STATES_H
