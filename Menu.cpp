//
// Created by Brandon Castro on 6/5/21.
//

#include "Menu.h"

Menu::Menu()
{
    initialize();
}

Menu::~Menu() {}

void Menu::draw(sf::RenderWindow &window) const
{
    window.draw(spider);
    window.draw(title);
    window.draw(play);
    window.draw(exit);
    window.draw(creator);
    window.draw(course);
    window.draw(CRN);
    window.draw(semester);
}

void Menu::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    sf::FloatRect bounds = play.getGlobalBounds();
    sf::Vector2f mPos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && bounds.contains(mPos))
    {
        this->active = false;
    }

    bounds = exit.getGlobalBounds();
    mPos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && bounds.contains(mPos))
    {
        window.close();
    }

    play.addEventHandler(window, event);
    exit.addEventHandler(window, event);
}

void Menu::update()
{
    play.update();
    exit.update();
}

void Menu::initialize()
{
    this->active = true;

    if (!texture.loadFromFile("spider.png"))
    {
        std::cout << "Error image could not load" << std::endl;
    }

    sf::Sprite background;
    background.setTexture(texture);
    background.setPosition(sf::Vector2f(50, 30));
    background.scale(sf::Vector2f(0.8, 0.7));

    this->spider = background;

    this->title.setString("Spider Solitaire");
    title.setFont(Fonts::getFont());
    title.setPosition(sf::Vector2f(90, 130));
    title.setScale(sf::Vector2f(4, 4));
    title.setColor(sf::Color::Red);

    Button play("Play");
    this->play = play;

    Button exit("Exit", 1);
    this->exit = exit;

    creator.setString("Brandon Castro");
    creator.setFont(Fonts::getFont());
    creator.setPosition(sf::Vector2f(30, 1400));
    creator.setColor(sf::Color::Red);
    creator.setScale(sf::Vector2f(2, 2));

    course.setString("Fundamentals Of Computer Science II");
    course.setFont(Fonts::getFont());
    course.setPosition(sf::Vector2f(400, 1400));
    course.setColor(sf::Color::Red);
    course.setScale(sf::Vector2f(2, 2));

    CRN.setString("31195");
    CRN.setFont(Fonts::getFont());
    CRN.setPosition(sf::Vector2f(1100, 1400));
    CRN.setColor(sf::Color::Red);
    CRN.setScale(sf::Vector2f(2, 2));

    semester.setString("Spring 2021");
    semester.setFont(Fonts::getFont());
    semester.setPosition(sf::Vector2f(1300, 1400));
    semester.setColor(sf::Color::Red);
    semester.setScale(sf::Vector2f(2, 2));

}

bool Menu::getState()
{
    return active;
}