#include <SFML/Graphics.hpp>
#include <iostream>

#include <core/pieces/bishop.hpp>
#include <core/tile.hpp>

#define WIDTH 420
#define HEIGHT 360

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML Window");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    window.setFramerateLimit(15);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Red);
        // for(int y = 0; y < 8; y++)
        //     for(int x; x < 8; x++)
        //         new Tile(&window, x, y, sf::Color::Green);

        Piece* piece = new Bishop(&window);
        //window.draw(shape);
        window.display();
    }

    // Piece* piece = new Bishop();
    // piece->move();
    // std::cout << piece->get_weight();

    return 0;
}