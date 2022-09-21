#include <iostream>
#include "SFML/Graphics.hpp"
#include "Menu.h"
#include "Game.h"

int main() {
    sf::RenderWindow window({2000, 1500, 32}, "Spider");
    Menu menu;
    Game game;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }

            if (menu.getState())
            {
                menu.addEventHandler(window, event);
            }
            else
            {
               game.addEventHandler(window, event);
            }
        }

        if (menu.getState())
        {
            menu.update();
        }
        else if (game.getState())
        {
            game.update();
        }
        else
        {
            window.close();
        }

        window.clear();

        if (menu.getState())
        {
            menu.draw(window);
        }
        else if (game.getState())
        {
            game.draw(window);
        }

        window.display();
    }

    return 0;
}
