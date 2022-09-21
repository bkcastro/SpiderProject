//
// Created by Brandon Castro on 6/6/21.
//

#include "Bounds.h"

Bounds::Bounds()
{
    for (int i = 0; i < 10; i++)
    {
        std::vector<sf::RectangleShape> temp;
        bounds.push_back(temp);
    }
}

void Bounds::printBounds() const
{
    for (int i = 0; i < 10; i++)
    {
        int hold = 0;

        for (int j = 0; j < bounds[i].size(); j++)
        {
            hold++;
        }

        std::cout << hold << std::endl;
    }
}

void Bounds::deleteBounds()
{
    for (int i = 0; i < 10; i++)
    {
        int size = bounds[i].size();
        for (int j = 0; j < size; j++)
        {
            bounds[i].pop_back();
        }

    }
}

void Bounds::checkBounds(const std::vector<std::vector<Card>> &field) {

    deleteBounds();
    for (int i = 0; i < 10; i++)
    {
        if (!field[i].empty())
        {
            // the first card will always be available to grab.
            sf::RectangleShape temp;
            temp.setPosition(field[i][field[i].size()-1].getPosition());
            temp.setSize({150,250});
            bounds[i].push_back(temp);

            for (int j = field[i].size()-1; j > 0; j--)
            {
                sf::RectangleShape temp;

                if (field[i][j-1].checkIfFlipped())
                {
                    break;
                }

                if (field[i][j].getRankInt()+1 == field[i][j-1].getRankInt())
                {
                    temp.setPosition(field[i][j-1].getPosition());
                    temp.setSize({150,40});
                    bounds[i].push_back(temp);
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            // if there is no card then add a bounds because user can place
            // card in that bound.
            sf::RectangleShape temp;
            float x = 240+(i*150)+(i*10);
            temp.setPosition(x, 100);
            temp.setSize({150,250});
            bounds[i].push_back(temp);
        }
    }
}

sf::Vector2f Bounds::getClick(sf::Vector2f mPos)
{
    sf::Vector2f card;
    sf::FloatRect contain;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < bounds[i].size(); j++)
        {
            contain = bounds[i][j].getGlobalBounds();

            if (contain.contains(mPos))
            {
                card.x = i;
                card.y = j;

                return card;
            }
        }
    }

    card.x = 100;
    card.y = 100;
    return card;
}

sf::Vector2f Bounds::getReleased(int origin, sf::Vector2f mPos)
{
    sf::Vector2f card;
    sf::FloatRect contain;

    for (int i = 0; i < 10; i++)
    {
        if (origin != i)
        {
            for (int j = 0; j < bounds[i].size(); j++)
            {
                contain = bounds[i][j].getGlobalBounds();

                if (contain.contains(mPos))
                {
                    card.x = i;
                    card.y = j;

                    return card;
                }
            }
        }
    }

    card.x = 100;
    card.y = 100;
    return card;
}

bool Bounds::checkForCompletedUnits()
{

    for (int i = 0; i < 10; i++)
    {
        if (bounds[i].size() == 13)
        {
            std::cout << "There is a completed unit!" << std::endl;
            return true;
        }
    }

    return false;
}

int Bounds::getIndexOfKingForCompletedUnit()
{
    int temp;
    for (int i = 0; i < 10; i++)
    {
        if (bounds[i].size() == 13)
        {
            temp = i;
            return temp;
        }
    }
}