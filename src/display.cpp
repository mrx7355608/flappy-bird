#include <SFML/Graphics.hpp>

sf::Sprite background;
sf::Texture backgroundTexture;

sf::Sprite base;
sf::Texture baseTexture;

sf::Image icon;

void loadBaseImage() {
    if (!baseTexture.loadFromFile("assets/sprites/base.png")) {
        throw "CANNOT LOAD BASE";
    }
    sf::Sprite baseSprite(baseTexture);
    baseSprite.setOrigin(0, -400);
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
