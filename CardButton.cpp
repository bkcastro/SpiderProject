//
// Created by Brandon Castro on 6/5/21.
//

#include "CardButton.h"

CardButton::CardButton() : CardButton({20,1300}) {

}

CardButton::CardButton(sf::Vector2f position)
{
    sf::Sprite::setTexture(Images::getImage(Images::BACKSIDE));
    sf::Sprite::setPosition(position);
    sf::Sprite::setScale({.7, .7});
}

void CardButton::addCard(Card card)
{
    size++;
    stack.push(card);
}

int CardButton::getSize() const
{
    return size;
}

Card CardButton::popCard()
{
    size--;
    return stack.pop();
}
