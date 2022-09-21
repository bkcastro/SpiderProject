//
// Created by Brandon Castro on 6/6/21.
//

#ifndef SPIDERPROJECT_BACKSIDE_H
#define SPIDERPROJECT_BACKSIDE_H
#include "SFML/Graphics.hpp"
#include "Images.h"

class Backside : public sf::Sprite{
public:
    Backside();

    bool check() const;
    void flip();
    void unflip();
private:
    // is state true then it is flipped;
    bool flipped = false;

};


#endif //SPIDERPROJECT_BACKSIDE_H
