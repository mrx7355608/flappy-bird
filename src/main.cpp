#include "../include/Display.h"
#include "../include/Globals.h"
#include "../include/Movement.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
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

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        continuousBaseMovement();

        window.clear();
        window.draw(background);
        window.draw(base);
        base.move(-1, 0);
        window.display();
    }
}
