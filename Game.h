//
// Created by Brandon Castro on 6/5/21.
//

#ifndef SPIDERPROJECT_GAME_H
#define SPIDERPROJECT_GAME_H
#include "Card.h"
#include "Deck.h"
#include "Button.h"
#include "CardButton.h"
#include "Field.h"
#include <vector>

class Game {
public:
    Game();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void draw(sf::RenderTarget& window) const;
    void initialize();
    void update();
    bool getState();

private:
    Button exit;
    Field field;
    CardButton cardButton;
    Deck deck;
    bool active;
};



#endif //SPIDERPROJECT_GAME_H
