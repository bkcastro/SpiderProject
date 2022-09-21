//
// Created by Brandon Castro on 6/6/21.
//

#include "Backside.h"

Backside::Backside()
{
    sf::Sprite::setTexture(Images::getImage(Images::BACKSIDE));
}

bool Backside::check() const {
    return flipped;
}

void Backside::flip() {
    flipped = true;
}

void Backside::unflip() {
    flipped = false;
}

