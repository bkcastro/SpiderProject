//
// Created by Brandon Castro on 6/5/21.
//

#include "Game.h"
Game::Game() {

    Button exit("Exit", {1800, 1400});
    this->exit = exit;

    initialize();

    field.updateBounds();
    field.printBounds();
}

void Game::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::FloatRect bounds;
    sf::Vector2f mPos = (sf::Vector2f) sf::Mouse::getPosition(window);

    bounds = exit.getGlobalBounds();
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && bounds.contains(mPos))
    {
        window.close();
    }

    bounds = cardButton.getGlobalBounds();
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && bounds.contains(mPos))
    {
        // here is where I add cards to field
        if (cardButton.clicked)
        {
            cardButton.clicked = false;
            std::cout << "CardButton clicked" << std::endl;

            if (cardButton.getSize() != 0)
            {
                for (int i = 0; i < 10; i++)
                {
                    field.addCard(i, cardButton.popCard());
                }
            }
        }
    }
    else
    {
        cardButton.clicked = true;
    }

    exit.addEventHandler(window, event);
    field.addEventHandler(window, event);
}

void Game::update()
{
    field.update();
    exit.update();

    if (field.getScore() == 8)
    {
        active = false;
    }
}

void Game::draw(sf::RenderTarget &window) const
{
    window.draw(field);
    window.draw(exit);
    if (cardButton.getSize() != 0)
    {
        window.draw(cardButton);
    }
}

void Game::initialize()
{
    this->active = true;
    this->deck.shuffle();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            Card card(static_cast<Rank::ranks>(deck.pop()));
            if (j < 3)
            {
                card.flip();
            }
            field.addCard(i, card);
        }
    }

    for (int i = 4; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            Card card(static_cast<Rank::ranks>(deck.pop()));
            if (j < 4)
            {
                card.flip();
            }
            field.addCard(i, card);
        }
    }

    int size = deck.getSize();
    std::cout << "deck size: " << size << std::endl;

    for(int i = 0; i < size; i++)
    {
        cardButton.addCard(deck.pop());
    }

    std::cout << "cardButton size: " << cardButton.getSize() << std::endl;
    std::cout << "deck size: " << deck.getSize() << std::endl;
}

bool Game::getState() {return active;}

