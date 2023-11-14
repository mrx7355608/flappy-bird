#include "../include/Display.h"
#include "../include/Globals.h"
#include "../include/Movement.h"
#include "../include/Pipe.h"
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

int main() {
    TextureLoader textureLoader;
    Movement movementManager;
    sf::Clock clock;

    // ========================
    //    Game window setup
    // ========================
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight),
                            "Flappy Bird");
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

    // Bird images
    sf::Texture upFlapTexture = textureLoader.loadBirdUpFlapTexture();
    sf::Sprite upFlapBird(upFlapTexture);
    upFlapBird.setPosition(100, 250);

    sf::Texture midFlapTexture = textureLoader.loadBirdMidFlapTexture();
    sf::Sprite midFlapBird(midFlapTexture);
    midFlapBird.setPosition(100, 250);

    sf::Texture downFlapTexture = textureLoader.loadBirdDownFlapTexture();
    sf::Sprite downFlapBird(downFlapTexture);
    downFlapBird.setPosition(100, 250);

    std::string flap = "up";

    float birdFlapTimer = clock.getElapsedTime().asMilliseconds();
    sf::Sprite birdImageToRender = upFlapBird;

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
    std::vector<sf::Sprite> *topPipesPtr = &topPipes;
    std::vector<sf::Sprite> *bottomPipesPtr = &bottomPipes;

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
        }

        // if the right-side of base image is close to right-side of game window
        // then it moves back the base image to its starting position and
        // creates an infinite base movement animation
        movementManager.continuousBaseMovement(baseImagePtr);

        // Spawn pipes after every 2 seconds
        float currentTime = clock.getElapsedTime().asSeconds();
        if (currentTime - lastPipeGenerationTime > 2) {
            pipesManager.spawnPipes(bottomPipesPtr, topPipesPtr);
            lastPipeGenerationTime = currentTime;
        }

        // After every 200 ms change the bird's current flap
        // image to make a flying animation
        float timeInMs = clock.getElapsedTime().asMilliseconds();
        if (timeInMs - birdFlapTimer > 250) {
            if (flap == "up") {
                flap = "mid";
                birdImageToRender = midFlapBird;
            } else if (flap == "mid") {
                flap = "down";
                birdImageToRender = downFlapBird;
            } else {
                birdImageToRender = upFlapBird;
                flap = "up";
            }
            birdFlapTimer = timeInMs;
        }

        // TODO: add a condition that removes pipes from arrays
        // when they are no longer displayed on screen

        window.clear();
        // Draw images on game window
        window.draw(backgroundImage);
        for (int i = 0; i < bottomPipes.size(); i++) {
            window.draw(bottomPipes[i]);
            bottomPipes[i].move(-2, 0);
        }
        for (int i = 0; i < topPipes.size(); i++) {
            window.draw(topPipes[i]);
            topPipes[i].move(-2, 0);
        }
        window.draw(baseImage);
        window.draw(birdImageToRender);

        // Move images on game window
        baseImage.move(-2, 0);

        // Update display
        window.display();
    }
}
