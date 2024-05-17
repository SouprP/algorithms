#ifndef TILE_H_
#define TILE_H_

#include <SFML/Graphics.hpp>

class Tile{
    private:
        //sf::RenderWindow* win;
        sf::RectangleShape rect;
        sf::Vector2f rect_size = sf::Vector2f(10, 10);
        sf::Vector2f pos;

    public:
        Tile(sf::RenderWindow* win, int pos_x, int pos_y, sf::Color color){
            rect.setSize(rect_size);
            rect.setFillColor(color);
            rect.setPosition(rect.getSize().x * pos_x, rect.getSize().y * pos_y);

            win->draw(rect);
        }
};


#endif