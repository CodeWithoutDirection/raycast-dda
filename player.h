#pragma once
#include <SFML/Graphics.hpp>
class Player{
public:
    sf::Vector2f pPos = sf::Vector2f(64.f*3 - 5.f,64.f*3-5.f);
    float speed = 1.f;
    sf::CircleShape shape;
    float radius = 5.f;

    Player(){
        shape.setRadius(radius);
        shape.setFillColor(sf::Color(255,255,0));
    }

    void draw(sf::RenderWindow &window){
        shape.setPosition(pPos);
        window.draw(shape);
    }

    void handleKeys(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) pPos.x += speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) pPos.x -= speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) pPos.y -= speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) pPos.y += speed;
    }

};