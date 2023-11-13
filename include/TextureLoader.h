#include <SFML/Graphics/Texture.hpp>

class TextureLoader {
  public:
    TextureLoader();

    sf::Texture loadBackgroundTexture();
    sf::Texture loadBaseTexture();
    sf::Texture loadPipeTexture();
    sf::Image loadGameIcon();
};
