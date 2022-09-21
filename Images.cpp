//
// Created by Brandon Castro on 6/5/21.
//

#include "Images.h"

std::vector<sf::Texture> Images::images(LAST, sf::Texture());

void Images::loadImage(image img)
{
    images[img].loadFromFile(getImagePath(img));
}

std::string Images::getImagePath(Images::image img)
{
    switch(img)
    {
        case ACE: return "Cards/AceOfSpades.png";
        case TWO: return "Cards/2OfSpades.png";
        case THREE: return "Cards/3OfSpades.png";
        case FOUR: return "Cards/4OfSpades.png";
        case FIVE: return "Cards/5OfSpades.png";
        case SIX: return "Cards/6OfSpades.png";
        case SEVEN: return "Cards/7OfSpades.png";
        case EIGHT: return "Cards/8OfSpades.png";
        case NINE: return "Cards/9OfSpades.png";
        case TEN: return "Cards/10OfSpades.png";
        case JACK: return "Cards/JackOfSpades.png";
        case QUEEN: return "Cards/QueenOfSpades.png";
        case KING: return "Cards/KingOfSpades.png";
        case BACKSIDE: return "Cards/backside.png";
    }
}

sf::Texture &Images::getImage(image img)
{
    loadImage(img);
    return images[img];
}


