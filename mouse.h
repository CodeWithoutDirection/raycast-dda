#pragma once
#include <SFML/Graphics.hpp>
#include "globals.h"

class Mouse{
    public:
        sf::Vector2i mPos;
        sf::CircleShape shape;
        float radius = 5.f;
    Mouse();
    void draw(sf::RenderWindow &, sf::Vector2i);
};

Mouse::Mouse(){
    shape.setFillColor(mouseColor);
    shape.setRadius(radius);
}

void Mouse::draw(sf::RenderWindow &window, sf::Vector2i _mousePos){
    mPos = _mousePos;
    shape.setPosition(sf::Vector2f(mPos.x-radius,mPos.y-radius));
    window.draw(shape);
}