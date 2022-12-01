#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

class Raycast{
    public:
        sf::Vector2f rayDir;
        float length;
    void castTo(sf::RenderWindow &, Player, Mouse);
    void draw(sf::RenderWindow &, Player, Mouse,Map);
};

void Raycast::castTo(sf::RenderWindow &window,Player _player,Mouse _mouse){
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    length = sqrt(pow((mousePos.x-_mouse.radius/2) - (_player.pPos.x+_player.radius/2),2)+pow((mousePos.y-_mouse.radius/2) - (_player.pPos.y+_player.radius/2),2));
    if (length == 0.f) rayDir = sf::Vector2f(0,-1);
    else rayDir = sf::Vector2f(((mousePos.x-_mouse.radius/2) - (_player.pPos.x+_player.radius/2))/length, ((mousePos.y-_mouse.radius/2) - (_player.pPos.y+_player.radius/2))/length);
}

void Raycast::draw(sf::RenderWindow &window, Player _player, Mouse _mouse, Map _map){

    sf::Vector2f rayUnitStepSize = sf::Vector2f(sqrt(1+pow(rayDir.y/rayDir.x,2)),sqrt(1+pow(rayDir.x/rayDir.y,2)));
    sf::Vector2f rayLength1D;
    sf::Vector2i mapCheck = sf::Vector2i((_player.pPos.x/_map.tileSize),(_player.pPos.y/_map.tileSize));
    sf::Vector2i step;

    if (rayDir.x < 0)
    {
        step.x = -1;
        rayLength1D.x = (_player.pPos.x-float(mapCheck.x*_map.tileSize))*rayUnitStepSize.x;
    }
    else 
    {
        step.x = 1;
        rayLength1D.x = (float(mapCheck.x+1)*_map.tileSize-_player.pPos.x)*rayUnitStepSize.x;
    }

    if (rayDir.y < 0)
    {
        step.y = -1;
        rayLength1D.y = (_player.pPos.y-float(mapCheck.y*_map.tileSize))*rayUnitStepSize.y;
    }
    else 
    {
        step.y = 1;
        rayLength1D.y = (float(mapCheck.y+1)*_map.tileSize-_player.pPos.y)*rayUnitStepSize.y;
    }
    bool tileFound = false;
    float maxDistance = 600.f;
    float distance = 0.f;
    while(!tileFound && distance < maxDistance)
    {
        if (rayLength1D.x < rayLength1D.y)
        {
            mapCheck.x += step.x;
            distance = rayLength1D.x;
            rayLength1D.x += rayUnitStepSize.x*_map.tileSize;
        }
        else
        {
            mapCheck.y += step.y;
            distance = rayLength1D.y;
            rayLength1D.y += rayUnitStepSize.y*_map.tileSize;
        }
        if (_map.map[mapCheck.y*(_map.maxX) + mapCheck.x] == 1)
        {
            tileFound = true;
        }
    }

    if (tileFound)
    {
        for (int i = 0; i <= distance; i+=10){
            sf::Vector2f intersection = sf::Vector2f(_player.pPos.x + rayDir.x * i,_player.pPos.y + rayDir.y * i);
            sf::CircleShape point;
            point.setRadius(2.f);
            point.setPosition(sf::Vector2f(intersection));
            window.draw(point);   
        }
    }
}
