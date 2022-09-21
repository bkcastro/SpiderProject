//
// Created by Brandon Castro on 6/5/21.
//

#ifndef SPIDERPROJECT_MENU_H
#define SPIDERPROJECT_MENU_H
#include "SFML/Graphics.hpp"
#include "Button.h"
#include <iostream>
#include "Fonts.h"

class Menu {

public:
    Menu();
    ~Menu();

    void draw(sf::RenderWindow &Window) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void initialize();
    bool getState();
private:

    Button play;
    Button exit;
    sf::Texture texture;
    sf::Sprite spider;
    sf::Text title;
    sf::Text creator;
    sf::Text course;
    sf::Text CRN;
    sf::Text semester;

    bool active;
};

#endif //SPIDERPROJECT_MENU_H
