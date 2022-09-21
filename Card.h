//
// Created by Brandon Castro on 6/5/21.
//

#ifndef SPIDERPROJECT_CARD_H
#define SPIDERPROJECT_CARD_H
#include "SFML/Graphics.hpp"
#include "Rank.h"
#include "Backside.h"
#include <string>

class Card : public sf::Drawable{
public:
    Card();
    Card(Rank::ranks rank);
    Card(Rank::ranks rank, float x, float y);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void setPosition(sf::Vector2f position);
    void setPositionToMouse(sf::Vector2f mPos);
    void resetOrigin();
    void flip();
    void unflip();
    // If this function returns true then the card is flipped
    bool checkIfFlipped() const;

    sf::Vector2f getPosition() const;
    std::string getRankString() const;
    int getRankInt() const;

    bool operator ==(Card& card) const;
private:

    Rank rank;
    Backside backside;

};


#endif //SPIDERPROJECT_CARD_H
