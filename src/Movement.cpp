#include "../include/Globals.h"
#include "../include/Movement.h"
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <vector>

// if the right-side of base image is close to right-side of game window
// then it moves back the base image to its starting position and
// creates an infinite base movement animation
void Movement::continuousBaseMovement(sf::Sprite *base) {
    const float basePosX = base->getPosition().x;
    const int rightSideOfBase = base->getLocalBounds().width + basePosX;

    if (rightSideOfBase < screenWidth + 10) {
        base->setPosition(0, 400);
    }
}

void Movement::moveBase(sf::Sprite *base) { base->move(-2, 0); }

void Movement::moveTopPipes(std::vector<sf::Sprite> *topPipesArray) {
    for (int i = 0; i < topPipesArray->size(); i++) {
        topPipesArray->at(i).move(-2, 0);
    }
}

void Movement::moveBottomPipes(std::vector<sf::Sprite> *bottomPipesArray) {
    for (int i = 0; i < bottomPipesArray->size(); i++) {
        bottomPipesArray->at(i).move(-2, 0);
    }
}
