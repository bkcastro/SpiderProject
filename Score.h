//
// Created by Brandon Castro on 6/8/21.
//

#ifndef SPIDERPROJECT_SCORE_H
#define SPIDERPROJECT_SCORE_H
#include "Backside.h"
#include <vector>

class Score : public sf::Drawable{
public:
    Score();
    int getScore() const;
    void addScore();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
private:
    int score;
    std::vector<Backside> imageScore;
};


#endif //SPIDERPROJECT_SCORE_H
