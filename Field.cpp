//
// Created by Brandon Castro on 6/6/21.
//

#include "Field.h"

Field::Field()
{
    for (int i = 0; i < 10; i++)
    {
        std::vector<Card>temp;
        field.push_back(temp);
    }
}

void Field::addCard(int i, Card card) {
    float x = 240+(i*150)+(i*10);
    float y = 100+(field[i].size()*40);
    card.setPosition({x,y});

    field[i].push_back(card);
}

void Field::printCards() const
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < field[i].size(); j++)
        {
            std::cout << field[i][j].getRankString() << std::endl;
        }
    }
}

void Field::printBounds() const
{
    bounds.printBounds();
}

int Field::getSize() const {
    int temp = 0;

    for (int i = 0; i < field.size(); i++)
    {
        for (int j = 0; j < field[i].size(); j++)
        {
            temp++;
        }
    }

    return temp;
}

void Field::draw(sf::RenderTarget& window, sf::RenderStates states) const{

    window.draw(score);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < field[i].size(); j++)
        {
            window.draw(field[i][j]);
        }
    }

    if (!basket.empty())
    {
        window.draw(basket);
    }
}

void Field::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    sf::Vector2f mPos = (sf::Vector2f) sf::Mouse::getPosition(window);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // bounds returns the card that was clicked if
        // the vector2i is {100,100} then the clicked is invalid.
        if (basket.empty())
        {
            sf::Vector2f place = bounds.getClick(mPos);
            if(place.x != 100 && !field[place.x].empty())
            {
                basket.setOrigin((int) place.x);
                std::cout << place.x << " " << place.y << std::endl;
                for (int i = (int) place.y; i >= 0;  i--)
                {
                    Card* card = &field[place.x][(field[place.x].size()-1)-i];
                    basket.addCard(card);
                }

            basket.print();
            }
        }
        else
        {
            basket.addEventHandler(window, event);
        }


        // add card or cards to basket and then display them!
    }
    else
    {
        // if basket is not empty when button is not pressed
        // delete all of its contents;
        if (!basket.empty())
        {
            // here is where I check if basket got released at a valid location
            sf::Vector2f released = bounds.getReleased(basket.getOrigin(), mPos);
            int origin = basket.getOrigin();
            std::cout << released.x << " " << released.y << std::endl;

            if (released.x == 100)
            {
                resetPosition(origin);
            }
            else if (!field[released.x].empty())
            {
                int receiver = field[released.x][field[released.x].size()-1].getRankInt();
                int giver = basket.getTopCardRank();
                std::cout << "Receiver and giver: " << receiver << " " << giver << std::endl;

                // make transfer
                if (receiver-1 == giver)
                {
                    for (int i = 0; i < basket.getSize(); i++)
                    {
                        Card temp = *(basket.getCardPoint(i));
                        addCard(released.x, temp);
                        field[origin].pop_back();
                    }

                    resetPosition(released.x);
                    update();
                    printBounds();
                    // call update bounds here too;
                }
                else
                {
                    resetPosition(origin);
                }
            }
            else
            {
                // so if field is empty then just add the cards
                for (int i = 0; i < basket.getSize(); i++) {
                    Card temp = *(basket.getCardPoint(i));
                    addCard(released.x, temp);
                    field[origin].pop_back();
                }

                resetPosition(released.x);
                update();
                printBounds();
            }

            basket.emptyBasket();
        }
    }
}

void Field::update()
{
    updateBounds();
    updateCard();
    checkForCompletedUnits();
}

void Field::updateBounds() {
    bounds.checkBounds(field);
}

void Field::updateCard()
{
    // goes through each top card of each vector then
    // if that card is flipped then unflip

    for (int i = 0; i < 10; i++)
    {
        if (top(i).checkIfFlipped())
        {
            field[i][field[i].size()-1].unflip();
        }
    }
}

Card Field::top(int i)
{
    return field[i][field[i].size()-1];
}

void Field::resetPosition(int o)
{
    for (int i = 0; i < field[o].size(); i++)
    {
        field[o][i].resetOrigin();
        float x = 240+(o*150)+(o*10);
        float y = 100+(i*40);
        field[o][i].setPosition({x,y});
    }
}

void Field::checkForCompletedUnits()
{
    if (bounds.checkForCompletedUnits())
    {
        int index = bounds.getIndexOfKingForCompletedUnit();

        for (int i = 0; i < 13; i++)
        {
            field[index].pop_back();
        }
        score.addScore();
    }
}

int Field::getScore() const
{
    return score.getScore();
}