#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <vector>

class Window {
  public:
    Window(sf::RenderWindow *);

    sf::RenderWindow *win;

    void drawBackgroundImage(sf::Sprite);
    void drawBottomPipes(std::vector<sf::Sprite> *);
    void drawTopPipes(std::vector<sf::Sprite> *);
    void drawBaseImage(sf::Sprite);
};
