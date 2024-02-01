#include "../include/Pipe.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <ctime>

const int pipePosCombos[5][2] = {{-120, 600}};

int generateRandomNumber() {
    srand(time(NULL));
    return rand() % 4;
}

Pipe::Pipe(sf::Texture pipeTxtre) { this->pipeTexture = pipeTxtre; }

sf::Sprite Pipe::createBottomPipe(int pipeX, int pipeY) {
    sf::Sprite bottomPipe(this->pipeTexture);
<<<<<<< HEAD
    // Get local bounds of a pipe
    sf::FloatRect pipeBounds = bottomPipe.getLocalBounds();
    // Set pipe origin
    bottomPipe.setOrigin(pipeBounds.width / 2, pipeBounds.height);
    // Set pipe position
=======
    // Set origin and position
    sf::FloatRect pipeBounds = bottomPipe.getLocalBounds();
    bottomPipe.setOrigin(pipeBounds.width / 2, pipeBounds.height);
>>>>>>> c4a60de58c7809cd080ba174aa64ae0ede96b65a
    bottomPipe.setPosition(pipeX, pipeY);
    return bottomPipe;
}

sf::Sprite Pipe::createTopPipe(int pipeX, int pipeY) {
    sf::Sprite topPipe(this->pipeTexture);
    // Set origin, position and angle
    sf::FloatRect pipeBounds = topPipe.getLocalBounds();
    topPipe.setOrigin(pipeBounds.width / 2, pipeBounds.height);
    topPipe.setPosition(pipeX, pipeY);
    topPipe.rotate(180);
    return topPipe;
}

void Pipe::spawnPipes(std::vector<sf::Sprite> *bottomPipes,
                      std::vector<sf::Sprite> *topPipes) {

    sf::Sprite topPipe = this->createTopPipe(300, -200);
    sf::Sprite bottomPipe = this->createBottomPipe(300, 520);
    bottomPipes->push_back(bottomPipe);
    topPipes->push_back(topPipe);
}
