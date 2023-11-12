#include "../include/Globals.h"
#include <SFML/Graphics.hpp>

const int screenWidth = 280;
const int screenHeight = 500;

sf::Sprite background;
sf::Sprite base;
sf::Image icon;
sf::Texture backgroundTexture;
sf::Texture baseTexture;

void loadBaseImage() {
    if (!baseTexture.loadFromFile("assets/sprites/base.png")) {
        throw "CANNOT LOAD BASE";
    }
    sf::Sprite baseSprite(baseTexture);
    baseSprite.setPosition(0, 400);
    base = baseSprite;
}

void loadBackgroundImage() {
    if (!backgroundTexture.loadFromFile("assets/sprites/background-day.png")) {
        throw "CANNOT LOAD BACKGROUND";
    }
    sf::Sprite bg(backgroundTexture);
    background = bg;
}

void loadIcon() {
    sf::Image iconImage;
    if (!iconImage.loadFromFile("assets/favicon.png")) {
        throw "CANNOT LOAD ICON";
    }
    icon = iconImage;
}

void continuousBaseMovement() {
    const float basePosX = base.getPosition().x;
    const int rightSideOfBase = base.getLocalBounds().width + basePosX;

    if (rightSideOfBase < screenWidth + 10) {
        base.setPosition(0, 400);
    }
}
