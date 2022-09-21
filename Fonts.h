//
// Created by Brandon Castro on 6/5/21.
//

#ifndef SPIDERPROJECT_FONTS_H
#define SPIDERPROJECT_FONTS_H
#include "SFML/Graphics.hpp"

class Fonts
{
private:
    static sf::Font font;
    static bool loaded;
    static void loadFont();
public:
    static sf::Font& getFont();
};



#endif //SPIDERPROJECT_FONTS_H
