//
// Created by Brandon Castro on 6/5/21.
//

#include "Rank.h"


Rank::Rank() : Rank(ACE) {}

Rank::Rank(ranks rank) : rank(rank)
{

    sf::Sprite::setTexture(Images::getImage(rankToImage()));
}

std::string Rank::rankToString() const
{
    switch(rank)
    {
        case ACE: return "A";
        case KING: return "K";
        case QUEEN: return "Q";
        case JACK: return "J";
        default:
            return std::to_string(rank);
    }
}

int Rank::rankToInt() const
{
    switch(rank)
    {
        case ACE: return 1;
        case TWO: return 2;
        case THREE: return 3;
        case FOUR: return 4;
        case FIVE: return 5;
        case SIX: return 6;
        case SEVEN: return 7;
        case EIGHT: return 8;
        case NINE: return 9;
        case TEN: return 10;
        case JACK: return 11;
        case QUEEN: return 12;
        case KING: return 13;
    }
}

int Rank::rankToInt(Rank::ranks rank) const
{
    switch(rank)
    {
        case ACE: return 1;
        case TWO: return 2;
        case THREE: return 3;
        case FOUR: return 4;
        case FIVE: return 5;
        case SIX: return 6;
        case SEVEN: return 7;
        case EIGHT: return 8;
        case NINE: return 9;
        case TEN: return 10;
        case JACK: return 11;
        case QUEEN: return 12;
        case KING: return 13;
    }
}

Images::image Rank::rankToImage() const
{
    switch(rank)
    {
        case ACE: return Images::ACE;
        case TWO: return Images::TWO;
        case THREE: return Images::THREE;
        case FOUR: return Images::FOUR;
        case FIVE: return Images::FIVE;
        case SIX: return Images::SIX;
        case SEVEN: return Images::SEVEN;
        case EIGHT: return Images::EIGHT;
        case NINE: return Images::NINE;
        case TEN: return Images::TEN;
        case JACK: return Images::JACK;
        case QUEEN: return Images::QUEEN;
        case KING: return Images::KING;
    }
}