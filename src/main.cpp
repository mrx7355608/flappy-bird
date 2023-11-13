#include "../include/Display.h"
#include "../include/Globals.h"
#include "../include/Movement.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

const int screenWidth = 280;
const int screenHeight = 500;

int main() {
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight),
                            "Flappy Bird");
    loadIcon();
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setFramerateLimit(60);

    loadBackgroundImage();
    loadBaseImage();

    // =================================
    //              PIPES
    // =================================
    sf::Clock clock;
    float lastPipeGenerationTime = clock.getElapsedTime().asSeconds();
    std::vector<sf::Sprite> pipes = {};

    sf::Texture pipeTexture;
    if (!pipeTexture.loadFromFile("assets/sprites/pipe-green.png")) {
        throw "CANNOT_LOAD_PIPE_SPRITES";
    }
    sf::Sprite pipe(pipeTexture);

    // Get local bounds of pipe
    sf::FloatRect localBounds = pipe.getLocalBounds();
    pipe.setOrigin(localBounds.width / 2, localBounds.height);

    pipe.setPosition(screenWidth + 30, 400);
    // =================================
    // =================================

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        continuousBaseMovement();

        // Pipe generation after every 3 seconds
        float currentTime = clock.getElapsedTime().asSeconds();
        if (currentTime - lastPipeGenerationTime > 2) {
            pipes.push_back(pipe);
            lastPipeGenerationTime = currentTime;
        }

        window.clear();
        window.draw(background);
        for (int i = 0; i < pipes.size(); i++) {
            window.draw(pipes[i]);
            pipes[i].move(-2, 0);
        }
        window.draw(base);
        base.move(-2, 0);
        window.display();
    }
}
