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
    std::vector<sf::Sprite> bottomPipes = {};
    std::vector<sf::Sprite> topPipes = {};

    loadBottomPipe();
    loadTopPipe();

    // Get local bounds of pipe
    sf::FloatRect localBounds = bottomPipe.getLocalBounds();
    // Set origin for rotation and positions
    int pipeXpos = screenWidth + 30;
    bottomPipe.setOrigin(localBounds.width / 2, localBounds.height);
    bottomPipe.setPosition(pipeXpos, 650);
    topPipe.setOrigin(localBounds.width / 2, localBounds.height);
    topPipe.setPosition(pipeXpos, -250);
    topPipe.rotate(180);

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
        if (currentTime - lastPipeGenerationTime > 1.5) {
            bottomPipes.push_back(bottomPipe);
            topPipes.push_back(topPipe);
            lastPipeGenerationTime = currentTime;
        }

        window.clear();
        window.draw(background);

        // Render bottom pipes
        for (int i = 0; i < bottomPipes.size(); i++) {
            window.draw(bottomPipes[i]);
            bottomPipes[i].move(-2, 0);
        }

        // Render top pipes
        for (int i = 0; i < topPipes.size(); i++) {
            window.draw(topPipes[i]);
            topPipes[i].move(-2, 0);
        }
        window.draw(base);
        base.move(-2, 0);
        window.display();
    }
}
