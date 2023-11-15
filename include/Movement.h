#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <vector>

extern std::vector<sf::Sprite> bottomPipes;
extern std::vector<sf::Sprite> topPipes;

extern int pipeXpos;
extern const int pipePosCombos[6][2];

void continuousBaseMovement();
void spawnPipes();

class Movement {
  public:
    void moveBase(sf::Sprite *);
    void continuousBaseMovement(sf::Sprite *);
    void moveTopPipes(std::vector<sf::Sprite> *);
    void moveBottomPipes(std::vector<sf::Sprite> *);
};

#endif
