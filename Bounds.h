//
// Created by Brandon Castro on 6/6/21.
//

#ifndef SPIDERPROJECT_BOUNDS_H
#define SPIDERPROJECT_BOUNDS_H
#include "SFML/Graphics.hpp"
#include <vector>
#include "Card.h"

// this class holds the bounds/positions of cards
// in the field that are clickable as in movable.
class Bounds {
public:
    Bounds();
    void checkBounds(const std::vector<std::vector<Card>> &field);
    sf::Vector2f getClick(sf::Vector2f mPos);
    sf::Vector2f getReleased(int origin, sf::Vector2f mPos);
    bool checkForCompletedUnits();
    int getIndexOfKingForCompletedUnit();
    void printBounds() const; // prints cards that are bound to each other

private:

    std::vector<std::vector<sf::RectangleShape>> bounds;
    void deleteBounds();

};


#endif //SPIDERPROJECT_BOUNDS_H
