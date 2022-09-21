//
// Created by Brandon Castro on 6/6/21.
//

#ifndef SPIDERPROJECT_BASKET_H
#define SPIDERPROJECT_BASKET_H
#include "SFML/Graphics.hpp"
#include "Card.h"
#include <vector>

class Basket : public sf::Drawable{
public:
    Basket();

    //Card pop(); // returns top card of the vector then deletes itself;
    void addCard(Card* card);
    bool empty() const;
    void emptyBasket();
    void print();
    void setOrigin(int i);
    int getOrigin() const;
    int getTopCardRank() const;
    int getSize() const;
    Card* getCardPoint(int i);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);

private:
    // this variable comes in handy when user places the cards
    // at an invalid location, so I set cards back to origin.
    int origin = -1;
    std::vector<Card*> basket;
};


#endif //SPIDERPROJECT_BASKET_H
