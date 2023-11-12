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

    const int pipeX = screenWidth + 30;
    sf::Texture pipeTexture;
    if (!pipeTexture.loadFromFile("assets/sprites/pipe-green.png")) {
        throw "CANNOT_LOAD_PIPE_SPRITES";
    }
    sf::Sprite pipe1(pipeTexture);
    sf::Sprite pipe2(pipeTexture);

    const sf::FloatRect pipeLocalBounds = pipe1.getLocalBounds();
    pipe1.setOrigin(pipeLocalBounds.width / 2, pipeLocalBounds.height);
    pipe2.setOrigin(pipeLocalBounds.width / 2, pipeLocalBounds.height);
    pipe1.rotate(180);

    std::vector<sf::Sprite> pipes = {};

    const int pipePosCombinations[8][2] = {
        {-50, 650},  {-100, 600}, {-150, 550}, {-200, 500},
        {-100, 650}, {-150, 600}, {-150, 550}, {-200, 500},
    };

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        continuousBaseMovement();

        if (pipe1.getPosition().x + pipe1.getLocalBounds().width < 0) {
            int randomNum = rand() % 7;
            pipe1.setPosition(pipeX, pipePosCombinations[randomNum][0]);
            pipe2.setPosition(pipeX, pipePosCombinations[randomNum][1]);
        }

        window.clear();
        window.draw(background);
        window.draw(pipe1);
        window.draw(pipe2);

        window.draw(base);
        base.move(-5, 0);

        pipe1.move(-5, 0);
        pipe2.move(-5, 0);

        window.display();
    }
}
