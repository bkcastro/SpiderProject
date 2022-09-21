//
// Created by Brandon Castro on 6/5/21.
//

#include "Button.h"

Button::Button() : Button("Text")
{

}

Button::Button(std::string text) : Button(text, 0)
{
}


Button::Button(std::string text, int num)
{

    background.setSize({200, 100});
    float x = WINDOWSIZE_X/2 - background.getSize().x/2;
    float y = WINDOWSIZE_Y/2 - background.getSize().y/2;
    if (num > 0)
    {
        y += (num*background.getSize().y)+5;
    }
    this->text.setString(text);
    background.setFillColor(color);
    background.setPosition(x,y);
    initialize();
}

Button:: Button(std::string text, sf::Vector2f position)
{
    background.setSize({100, 60});
    this->text.setString(text);
    background.setFillColor(color);
    background.setPosition(position);
    initialize();
}

void Button::center()
{
    sf::FloatRect bBounds = background.getGlobalBounds();
    sf::FloatRect tBounds = text.getGlobalBounds();

    text.setPosition(bBounds.width/2 +background.getPosition().x- tBounds.width/2,
                     bBounds.top +bBounds.height/2 - tBounds.height);
}
void Button::initialize()
{
    text.setFont(Fonts::getFont());
    text.setColor(sf::Color::Black);
    text.setScale({2,2});
    center();

}


//polymorphism, you can see this by holding command (control) and clicking on the class name
void Button::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(background);
    window.draw(text);
}

//event handler
void Button::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    hover(window, event);
}

//make any necessary updates
void Button::update()
{

    if(checkState(HOVERED))
        background.setFillColor(sf::Color::Red);
    if(checkState(NORMAL))
        background.setFillColor(color);
}

bool Button::hover(sf::RenderWindow& window, sf::Event event)
{
    sf::FloatRect bBounds = background.getGlobalBounds();
    sf::Vector2f mPos = static_cast<sf::Vector2f>( sf::Mouse::getPosition(window));

    if(bBounds.contains(mPos))
    {
        enableState(HOVERED);
        disableState(NORMAL);
        return true;
    }

    else
    {
        enableState(NORMAL);
        disableState(HOVERED);
        return false;
    }
}


sf::FloatRect Button::getGlobalBounds()
{
    return background.getGlobalBounds();
}