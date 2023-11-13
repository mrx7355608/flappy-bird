#include "../include/Globals.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

sf::Texture backgroundTexture;
sf::Sprite background;

sf::Sprite base;
sf::Texture baseTexture;

sf::Texture pipeTexture;
sf::Sprite bottomPipe;
sf::Sprite topPipe;

sf::Image icon;

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

void loadBottomPipe() {
    sf::FloatRect localBounds = bottomPipe.getLocalBounds();
    bottomPipe.setOrigin(localBounds.width / 2, localBounds.height);
}

void loadTopPipe() {
    if (!pipeTexture.loadFromFile("assets/sprites/pipe-green.png")) {
        throw "CANNOT_LOAD_PIPE_SPRITES";
    }
    sf::Sprite tPipe(pipeTexture);
    topPipe = tPipe;
    sf::FloatRect localBounds = topPipe.getLocalBounds();
    topPipe.setOrigin(localBounds.width / 2, localBounds.height);
    topPipe.rotate(180);
}
