#include "../include/Globals.h"
#include <iostream>
#include <vector>

std::vector<sf::Sprite> bottomPipes = {};
std::vector<sf::Sprite> topPipes = {};

int pipeXpos = screenWidth + 30;
const int pipePosCombos[6][2] = {{-50, 650},  {-100, 600}, {-150, 550},
                                 {-200, 500}, {-250, 450}, {-150, 400}};

void continuousBaseMovement() {
    const float basePosX = base.getPosition().x;
    const int rightSideOfBase = base.getLocalBounds().width + basePosX;

    if (rightSideOfBase < screenWidth + 10) {
        base.setPosition(0, 400);
    }
}

int generateRandomNumber() {
    srand(time(NULL));
    int randomNumber = rand() % 5;
    return randomNumber;
}

void spawnPipes() {
    int randomNumber = generateRandomNumber();
    std::cout << randomNumber << '\n';
    bottomPipe.setPosition(pipeXpos, pipePosCombos[randomNumber][1]);
    topPipe.setPosition(pipeXpos, pipePosCombos[randomNumber][0]);
    bottomPipes.push_back(bottomPipe);
    topPipes.push_back(topPipe);
}
