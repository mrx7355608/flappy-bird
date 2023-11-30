#include "../include/Globals.h"
#include "../include/Movement.h"
#include "../include/Pipe.h"
#include "../include/TextureLoader.h"
#include "../include/Window.h"
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

int main() {
    TextureLoader textureLoader;
    Movement movementManager;
    sf::Clock clock;

    // ========================
    //    Game window setup
    // ========================
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Game");
    window.setVerticalSyncEnabled(true);
    sf::RenderWindow *win = &window;
    Window windowManager(win);

    window.setFramerateLimit(60);
    sf::Image icon = textureLoader.loadGameIcon();
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    // ############################

    // ========================
    //      Loading Images
    // ========================
    // Backgrond image
    sf::Texture backgroundTexture = textureLoader.loadBackgroundTexture();
    sf::Sprite backgroundImage(backgroundTexture);

    // Base image
    sf::Texture baseTexture = textureLoader.loadBaseTexture();
    sf::Sprite baseImage(baseTexture);
    baseImage.setPosition(0, 400);

    // ========================
    //      Handling Bird
    // ========================
    double birdVelocity = 1.0;
    float gravity = 1.8;
    float lastTime = clock.getElapsedTime().asMilliseconds();
    sf::Texture upFlapTexture = textureLoader.loadBirdUpFlapTexture();
    sf::Sprite upFlapBird(upFlapTexture);
    upFlapBird.setScale(0.9, 0.9);
    upFlapBird.setPosition(50.0f, 200.0f);

    sf::Texture midFlapTexture = textureLoader.loadBirdMidFlapTexture();
    sf::Sprite midFlapBird(midFlapTexture);

    sf::Texture downFlapTexture = textureLoader.loadBirdDownFlapTexture();
    sf::Sprite downFlapBird(downFlapTexture);

    // ############################

    // ========================
    //      Handling Pipes
    // ========================
    sf::Texture pipeTexture = textureLoader.loadPipeTexture();
    float lastPipeGenerationTime = clock.getElapsedTime().asSeconds();
    Pipe pipesManager(pipeTexture);
    // Using arrays to store pipes so that multiple pipes can be
    // rendered using a for loop
    std::vector<sf::Sprite> bottomPipes = {};
    std::vector<sf::Sprite> topPipes = {};
    // ############################

    // Pointers
    sf::Sprite *baseImagePtr = &baseImage;
    std::vector<sf::Sprite> *topPipesArrayPtr = &topPipes;
    std::vector<sf::Sprite> *bottomPipesArrayPtr = &bottomPipes;

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Space) {
                birdVelocity = 4 * -(gravity);
            }
        }

        std::cout << birdVelocity << std::endl;

        // Spawn pipes after every 2 seconds
        float currentTime = clock.getElapsedTime().asSeconds();
        if (currentTime - lastPipeGenerationTime > 2) {
            pipesManager.spawnPipes(bottomPipesArrayPtr, topPipesArrayPtr);
            lastPipeGenerationTime = currentTime;
        }

        float currentTimeInMs = clock.getElapsedTime().asMilliseconds();
        if (currentTimeInMs - lastTime > 100) {
            birdVelocity += gravity;
            lastTime = currentTimeInMs;
        }
        // TODO: add a condition that removes pipes from arrays
        // when they are no longer displayed on screen

        window.clear();

        // Draw images on game window
        windowManager.drawBackgroundImage(backgroundImage);
        windowManager.drawBottomPipes(bottomPipesArrayPtr);
        windowManager.drawTopPipes(topPipesArrayPtr);
        windowManager.drawBaseImage(baseImage);
        window.draw(upFlapBird);

        // Move images on game window
        movementManager.moveTopPipes(topPipesArrayPtr);
        movementManager.moveBottomPipes(bottomPipesArrayPtr);

        // Repositions the base image when it is about
        // to leave the right-side of the main game window
        movementManager.continuousBaseMovement(baseImagePtr);
        // just moves the base with the speed of 2
        movementManager.moveBase(baseImagePtr);
        upFlapBird.move(0, birdVelocity);

        // Update display
        window.display();
    }
}
