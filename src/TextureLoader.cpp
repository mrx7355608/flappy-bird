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
        throw "CANNOT_LOAD_BASE_TEXTURE";
    }
    return baseTexture;
}

sf::Texture TextureLoader::loadPipeTexture() {
    sf::Texture pipeTexture;
    if (!pipeTexture.loadFromFile("assets/sprites/pipe-green.png")) {
        throw "CANNOT_LOAD_PIPE_TEXTURE";
    }
    return pipeTexture;
}

sf::Image TextureLoader::loadGameIcon() {
    sf::Image iconImage;
    if (!iconImage.loadFromFile("assets/favicon.png")) {
        throw "CANNOT_LOAD_ICON";
    }
    return iconImage;
}

sf::Texture TextureLoader::loadBirdUpFlapTexture() {
    sf::Texture upFlapTexture;
    if (!upFlapTexture.loadFromFile("assets/sprites/bluebird-upflap.png")) {
        throw "CANNOT_LOAD_BIRD_TEXTURE";
    }
    return upFlapTexture;
}

sf::Texture TextureLoader::loadBirdMidFlapTexture() {
    sf::Texture midFlapTexture;
    if (!midFlapTexture.loadFromFile("assets/sprites/bluebird-midflap.png")) {
        throw "CANNOT_LOAD_BIRD_TEXTURE";
    }
    return midFlapTexture;
}

sf::Texture TextureLoader::loadBirdDownFlapTexture() {
    sf::Texture downFlapTexture;
    if (!downFlapTexture.loadFromFile("assets/sprites/bluebird-downflap.png")) {
        throw "CANNOT_LOAD_BIRD_TEXTURE";
    }
    return downFlapTexture;
}
