#include "../include/Pipe.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

Pipe::Pipe(sf::Texture pipeTxtre) { this->pipeTexture = pipeTxtre; }

sf::Sprite Pipe::createBottomPipe(int pipeX) {
    sf::Sprite bottomPipe(this->pipeTexture);
    // Set origin and position
    sf::FloatRect pipeBounds = bottomPipe.getLocalBounds();
    bottomPipe.setOrigin(pipeBounds.width / 2, pipeBounds.height);
    bottomPipe.setPosition(pipeX, 500);
    return bottomPipe;
}

sf::Sprite Pipe::createTopPipe(int pipeX) {
    sf::Sprite topPipe(this->pipeTexture);
    // Set origin, position and angle
    sf::FloatRect pipeBounds = topPipe.getLocalBounds();
    topPipe.setOrigin(pipeBounds.width / 2, pipeBounds.height);
    topPipe.setPosition(pipeX, -200);
    topPipe.rotate(180);
    return topPipe;
}

void Pipe::spawnPipes(std::vector<sf::Sprite> *bottomPipes,
                      std::vector<sf::Sprite> *topPipes) {
    sf::Sprite topPipe = this->createTopPipe(300);
    sf::Sprite bottomPipe = this->createBottomPipe(300);
    bottomPipes->push_back(bottomPipe);
    topPipes->push_back(topPipe);
}
