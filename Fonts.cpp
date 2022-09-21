//
// Created by Brandon Castro on 6/5/21.
//

#include "Fonts.h"

sf::Font Fonts::font;
bool Fonts::loaded = false;
void Fonts::loadFont()
{
    if(!loaded)
    {
        if(!font.loadFromFile("fonts/Amatic-Bold.ttf"))
            exit(1);
        loaded = true;
    }

}

sf::Font& Fonts::getFont()
{
    loadFont();
    return font;
}