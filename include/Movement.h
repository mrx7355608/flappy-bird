#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

extern std::vector<sf::Sprite> bottomPipes;
extern std::vector<sf::Sprite> topPipes;

extern int pipeXpos;
extern const int pipePosCombos[6][2];

void continuousBaseMovement();
void spawnPipes();

#endif
