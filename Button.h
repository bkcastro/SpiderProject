//
// Created by Brandon Castro on 6/5/21.
//

#ifndef SPIDERPROJECT_BUTTON_H
#define SPIDERPROJECT_BUTTON_H
#include "SFML/Graphics.hpp"
#include "Images.h"
#include "Fonts.h"
#include "States.h"
#include <vector>

#define WINDOWSIZE_X 2000
#define WINDOWSIZE_Y 1500

class Button : public sf::Drawable, public sf::Transformable, public States {

private:

    sf::RectangleShape background;
    sf::Text text;
    sf::Color color = sf::Color::White;
    void center();
    void initialize();
    bool hover(sf::RenderWindow& window, sf::Event event);

public:
    Button();
    Button(std::string text, int num);
    Button(std::string text, sf::Vector2f position);
    Button(std::string text);

    //polymorphism, pure virtual function defined
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //event handler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);

    //make any necessary updates
    void update();

    sf::FloatRect getGlobalBounds();
};


#endif //SPIDERPROJECT_BUTTON_H
