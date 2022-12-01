#pragma once
#include <SFML/Graphics.hpp>
#include "globals.h"

class Map{
    public:
        int maxX = 16;
        int maxY = 16;
        int tileSize = 32;
        int map[256]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,0,1,0,0,0,0,1,0,0,0,0,0,1,0,1,
                     1,0,1,0,0,0,1,1,0,1,0,0,0,1,0,1,
                     1,0,0,0,0,0,0,0,1,0,1,0,0,1,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,1,0,1,1,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    void draw(sf::RenderWindow &);
};

void Map::draw(sf::RenderWindow &window){
    for (int x = 0; x < maxX; x++){
        for (int y = 0; y < maxY; y++){
            if (map[y*maxX + x] == 1){
                sf::RectangleShape wall;
                wall.setPosition(sf::Vector2f(x*tileSize+1,y*tileSize+1));
                wall.setFillColor(wallColor);
                wall.setSize(sf::Vector2f(tileSize-1,tileSize-1));
                window.draw(wall);
            }
            if (map[y*maxX + x] == 0){
                sf::RectangleShape floor;
                floor.setPosition(sf::Vector2f(x*tileSize+1,y*tileSize+1));
                floor.setFillColor(floorColor);
                floor.setSize(sf::Vector2f(tileSize-1,tileSize-1));
                window.draw(floor);
            }
        }
    }

}

