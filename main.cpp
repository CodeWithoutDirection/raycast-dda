#include <SFML/Graphics.hpp>
#include <iostream>
#include "header/player.h"
#include "header/map.h"
#include "header/mouse.h"
#include "header/raycast.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "Raycasting test 1", sf::Style::Close);
    window.setFramerateLimit(50);
    window.setMouseCursorVisible(false);
    Player player = Player();
    Mouse mouse = Mouse();
    Map map = Map();
    Raycast raycast = Raycast();
    while (window.isOpen())
    {
        window.clear(sf::Color(21.f,105.f,129.f));
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        map.draw(window);
        mouse.draw(window,sf::Mouse::getPosition(window));
        player.draw(window);
        player.handleKeys();
        raycast.castTo(window,player,mouse);
        raycast.draw(window,player,mouse,map);
        window.display();
    }

    return 0;
}