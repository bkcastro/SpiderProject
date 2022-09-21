//
// Created by Brandon Castro on 6/8/21.
//

#include "Score.h"

Score::Score() : score(0){

}

int Score::getScore() const {
    return score;
}

void Score::addScore(){

    Backside image;
    image.setPosition(30, (float) (200+(score*20)));
    image.setScale(.6,.6);
    image.rotate(-90);

    imageScore.push_back(image);

    score++;
}

void Score::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    for (int i = 0; i < imageScore.size(); i++)
    {
        window.draw(imageScore[i]);
    }
}
