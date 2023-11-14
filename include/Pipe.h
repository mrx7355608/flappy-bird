#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
class Pipe {
  public:
    Pipe(sf::Texture);

    sf::Texture pipeTexture;

    sf::Sprite createTopPipe(int);
    sf::Sprite createBottomPipe(int);
    void spawnPipes(std::vector<sf::Sprite> *, std::vector<sf::Sprite> *);
};
