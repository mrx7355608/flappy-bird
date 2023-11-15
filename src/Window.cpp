#include "../include/Window.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

Window::Window(sf::RenderWindow *win) { this->win = win; };

void Window::drawBackgroundImage(sf::Sprite backgroundImage) {
    this->win->draw(backgroundImage);
}

void Window::drawBottomPipes(std::vector<sf::Sprite> *bottomPipesArr) {
    for (int i = 0; i < bottomPipesArr->size(); i++) {
        sf::Sprite bottomPipe = bottomPipesArr->at(i);
        this->win->draw(bottomPipe);
    }
}

void Window::drawTopPipes(std::vector<sf::Sprite> *topPipesArr) {
    for (int i = 0; i < topPipesArr->size(); i++) {
        sf::Sprite topPipe = topPipesArr->at(i);
        this->win->draw(topPipe);
    }
}

void Window::drawBaseImage(sf::Sprite base) { this->win->draw(base); }
