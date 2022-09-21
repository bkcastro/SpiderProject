//
// Created by Brandon Castro on 6/5/21.
//

#ifndef SPIDERPROJECT_DECK_H
#define SPIDERPROJECT_DECK_H
#include "Card.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>
// size of deck is 104

class Deck {
public:
    Deck();

    int getSize() const;
    Rank::ranks pop();
    void shuffle();
    void printDeck() const;

private:
    std::vector<Rank::ranks> deck;
};


#endif //SPIDERPROJECT_DECK_H
