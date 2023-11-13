#include "../include/Display.h"
#include "../include/Globals.h"
#include "../include/Movement.h"
#include "../include/TextureLoader.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

const int screenWidth = 280;
const int screenHeight = 500;

sf::Texture birdTexture;
sf::Sprite bird;

int main() {
    TextureLoader textureLoader;
    Movement movementManager;
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight),
                            "Flappy Bird");
    window.setFramerateLimit(60);

    // Set game window icon
    sf::Image icon = textureLoader.loadGameIcon();
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Textures
    sf::Texture backgroundTexture = textureLoader.loadBackgroundTexture();
    sf::Texture baseTexture = textureLoader.loadBaseTexture();
    sf::Texture pipeTexture = textureLoader.loadPipeTexture();

    // Sprites
    sf::Sprite backgroundImage(backgroundTexture);
    sf::Sprite pipe(pipeTexture);
    sf::Sprite baseImage(baseTexture);
    baseImage.setPosition(0, 400);

    // Pointers
    sf::Sprite *baseImagePtr = &baseImage;

    // =================================
    //              PIPES
    // =================================
    sf::Clock clock;
    float lastPipeGenerationTime = clock.getElapsedTime().asSeconds();
    loadBottomPipe();
    loadTopPipe();

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // if the right-side of base image is close to right-side of game window
        // then it moves back the base image to its starting position and
        // creates an infinite base movement animation
        movementManager.continuousBaseMovement(baseImagePtr);

        // Pipe generation after every 1.5 seconds
        float currentTime = clock.getElapsedTime().asSeconds();
        if (currentTime - lastPipeGenerationTime > 1.5) {
            spawnPipes();
            lastPipeGenerationTime = currentTime;
        }

        window.clear();
        // Draw images on game window
        window.draw(backgroundImage);
        window.draw(baseImage);

        // Continuously move base towards left side
        baseImage.move(-2, 0);

        // Update display
        window.display();
    }
}
