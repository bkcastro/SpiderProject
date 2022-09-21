//
// Created by Brandon Castro on 6/6/21.
//

#ifndef SPIDERPROJECT_FIELD_H
#define SPIDERPROJECT_FIELD_H
#include "Card.h"
#include "Bounds.h"
#include "Basket.h"
#include "Score.h"
#include <vector>

class Field : public sf::Drawable{
public:
    Field();

    void printCards() const;
    void addCard(int i, Card card);
    Card top(int i);
    int getSize() const;
    void update();
    void checkForCompletedUnits();
    // resetsPositions
    void resetPosition(int o);
    void updateBounds();
    void updateCard();
    void printBounds() const;
    int getScore() const;

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
private:
    std::vector<std::vector<Card>> field;
    Bounds bounds;
    Basket basket;
    Score score;

};


#endif //SPIDERPROJECT_FIELD_H
