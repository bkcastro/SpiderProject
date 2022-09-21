//
// Created by Brandon Castro on 6/5/21.
//

#include "Card.h"

Card::Card() : Card(Rank::ACE){
}

Card::Card(Rank::ranks rank) : Card(rank, 0, 0){
}

Card::Card(Rank::ranks rank, float x, float y) : rank(rank){
    this->rank.setPosition(x, y);
    this->backside.setPosition(x, y);
}

void Card::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (backside.check())
    {
        window.draw(backside);
    }
    else
    {
        window.draw(rank);
    }

}

void Card::addEventHandler(sf::RenderWindow& window, sf::Event event)
{

}

std::string Card::getRankString() const {
    return rank.rankToString();
}

int Card::getRankInt() const
{
    return rank.rankToInt();
}

void Card::setPosition(sf::Vector2f position)
{
    rank.setPosition(position);
    backside.setPosition(position);
}

void Card::setPositionToMouse(sf::Vector2f mPos) {

    rank.setOrigin(rank.getGlobalBounds().width/2, rank.getGlobalBounds().height/2);
    rank.setPosition(mPos);
    backside.setOrigin(rank.getGlobalBounds().width/2, rank.getGlobalBounds().height/2);
    backside.setPosition(mPos);
}

sf::Vector2f Card::getPosition() const
{
    return rank.getPosition();
}

bool Card::operator ==(Card& card) const
{
    if (getPosition() == card.getPosition())
    {
        return true;
    }

    return false;
}

void Card::flip() {
    backside.flip();
}

void Card::unflip() {
    backside.unflip();
}

bool Card::checkIfFlipped() const
{
    if (backside.check())
    {
        return true;
    }

    return false;
}

void Card::resetOrigin()
{
    if(rank.getOrigin().x > 0)
    {
        sf::Vector2f hold = rank.getOrigin();
        float x = rank.getPosition().x-hold.x;
        float y = rank.getPosition().y-hold.y;
        rank.setOrigin(0,0);
        rank.setPosition(x, y);
        backside.setOrigin(0,0);
        backside.setPosition(x, y);
    }
}