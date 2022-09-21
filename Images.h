//
// Created by Brandon Castro on 6/5/21.
//

#ifndef SPIDERPROJECT_IMAGES_H
#define SPIDERPROJECT_IMAGES_H
#include <SFML/Graphics.hpp>

class Images {
public:
    enum image {
        ACE = 0, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, BACKSIDE, LAST
    };

private:
    static std::vector<sf::Texture> images;
    static void loadImage(image img);
    static std::string getImagePath(image img);

public:
    static sf::Texture& getImage(image img);
};


#endif //SPIDERPROJECT_IMAGES_H
