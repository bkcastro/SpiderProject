//
// Created by Brandon Castro on 6/5/21.
//

#include "Deck.h"

Deck::Deck() {

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            auto temp = static_cast<Rank::ranks>(j);

            deck.push_back(temp);
        }
    }
}

int Deck::getSize() const {
    return deck.size();
}

void Deck::printDeck() const
{
    for (int i = 0; i < deck.size(); i++)
    {
        std::cout << std::to_string(deck[i]) << std::endl;
    }
}

void Deck::shuffle()
{
    std::random_shuffle(deck.begin(), deck.end());
}

Rank::ranks Deck::pop() {
    Rank::ranks temp = deck[deck.size()-1];
    deck.pop_back();
    return temp;
}
