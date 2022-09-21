//
// Created by Brandon Castro on 6/6/21.
//

#include "Basket.h"

Basket::Basket() {}

//Card* Basket::pop()
//{
//    Card* temp = basket[basket.size()-1];
//    basket.pop_back();
//    return temp;
//}

void Basket::addCard(Card* card) {
    basket.push_back(card);
}

bool Basket::empty() const{
    return basket.empty();
}

void Basket::print()
{
    for (int i = 0; i < basket.size(); i++)
    {
        std::cout << basket[i]->getRankInt() << std::endl;
    }
}

void Basket::emptyBasket()
{
    origin = -1;
    int size = basket.size();
    for (int i = 0; i < size; i++) {
        basket.pop_back();
    }
}

void Basket::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    sf::Vector2f mPos = (sf::Vector2f) sf::Mouse::getPosition(window);

    for (int i = 0; i < basket.size(); i++)
    {
        mPos.y = mPos.y + (float)(40);
        basket[i]->setPositionToMouse(mPos);
    }
}

void Basket::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < basket.size(); i++)
    {
        window.draw(*basket[i]);
    }
}



void Basket::setOrigin(int i)
{
    origin = i;
}

int Basket::getOrigin() const
{
    return origin;
}

int Basket::getTopCardRank() const
{
    return basket[0]->getRankInt();
}

int Basket::getSize() const
{
    return basket.size();
}

Card* Basket::getCardPoint(int i)
{
    Card* point = basket[i];
    return point;
}