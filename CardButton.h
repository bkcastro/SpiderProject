//
// Created by Brandon Castro on 6/5/21.
//

#ifndef SPIDERPROJECT_CARDBUTTON_H
#define SPIDERPROJECT_CARDBUTTON_H
#include "SFML/Graphics.hpp"
#include "Images.h"
#include "Card.h"
#include "States.h"
#include "Stack.h"

class CardButton : public sf::Sprite {
public:
    CardButton();
    CardButton(sf::Vector2f position);

    void addCard(Card card);
    Card popCard(); // returns top card and deletes it from pool
    int getSize() const;
    bool empty() const;
    bool clicked = false;

private:
    // cards added to pool should already be shuffled!
    int size = 0;
    Stack stack;

};


#endif //SPIDERPROJECT_CARDBUTTON_H
