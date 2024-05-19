#include <SFML/Graphics.hpp>
#include <iostream>

#include <core/pieces/bishop.hpp>
#include <core/tile.hpp>
#include <core/logic.hpp>
#include <core/board.hpp>

#include <layout/button.hpp>

#define WIDTH 960+25
#define HEIGHT 480+50

sf::Font pixel_font;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML Chess", sf::Style::Close);
    pixel_font.loadFromFile("../fonts/pixel.ttf");


    window.setFramerateLimit(15);

    Button myButton(sf::Vector2f(120, 50), sf::Vector2f(240, 100), "random gen", pixel_font);
    myButton.setCallback([]() {
        std::cout << "Button Clicked!\n";
    });

    Board* board = new Board(&window);
    board->setup_pieces(true);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            myButton.handleEvent(event);
        }

        window.clear(sf::Color::Black);
        // for(int y = 0; y < 8; y++)
        //     for(int x; x < 8; x++)
        //         new Tile(&window, x, y, sf::Color::Green);

        //Piece* piece = new Bishop(&window);
        //window.draw(shape);
        board->setup();
        board->draw();
        myButton.draw(window);
        window.display();
    }

    // Piece* piece = new Bishop();
    // piece->move();
    // std::cout << piece->get_weight();

    return 0;
}