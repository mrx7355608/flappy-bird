#include "../include/TextureLoader.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>

// Constructor
TextureLoader::TextureLoader(){};

sf::Texture TextureLoader::loadBackgroundTexture() {
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/sprites/background-day.png")) {
        throw "CANNOT LOAD BACKGROUND";
    }
    return backgroundTexture;
}

sf::Texture TextureLoader::loadBaseTexture() {
    sf::Texture baseTexture;
    if (!baseTexture.loadFromFile("assets/sprites/base.png")) {
        throw "CANNOT LOAD BASE";
    }
    return baseTexture;
}

sf::Texture TextureLoader::loadPipeTexture() {
    sf::Texture pipeTexture;
    if (!pipeTexture.loadFromFile("assets/sprites/pipe-green.png")) {
        throw "CANNOT_LOAD_PIPE_SPRITES";
    }
    return pipeTexture;
}

sf::Image TextureLoader::loadGameIcon() {
    sf::Image iconImage;
    if (!iconImage.loadFromFile("assets/favicon.png")) {
        throw "CANNOT LOAD ICON";
    }
    return iconImage;
}
