//
// Created by Brandon Castro on 6/5/21.
//

#ifndef SPIDERPROJECT_RANK_H
#define SPIDERPROJECT_RANK_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Images.h"

class Rank : public sf::Sprite{
public:
    enum ranks
    {
        ACE = 0, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
    };
    Rank();
    Rank(ranks ranks);
    std::string rankToString() const;
    int rankToInt() const;
    int rankToInt(Rank::ranks rank) const;
    ranks rank;
private:
    Images::image rankToImage() const;
};

#endif //SPIDERPROJECT_RANK_H
