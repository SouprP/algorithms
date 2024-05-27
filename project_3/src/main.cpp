#include <SFML/Graphics.hpp>
#include <iostream>

#include <core/tile.hpp>
#include <core/logic.h>
#include <core/board.h>

#include <layout/button.hpp>
#include <layout/textbox.hpp>
#include <layout/label.hpp>

//#define WIDTH 960+25
//#define HEIGHT 480+50
#define WIDTH 300
#define HEIGHT 400

sf::Font pixel_font;

int* menu(){
    // Creation of window and it's settings
    sf::RenderWindow menu_window;
    int* info = new int[3];
    info[2] = 0;

    // Matrix setup
    Label matrix_label(100, 25, "Board size", pixel_font, 20);
    TextBox matrix_input(50, 65, 200, 50, pixel_font, 24);
    matrix_input.setText("5");

    // Win condition setup
    Label cond_label(100, 150, "Win condition", pixel_font, 20);
    TextBox cond_input(50, 190, 200, 50, pixel_font, 24);
    cond_input.setText("3");

    // Start game button
    Button start_button(sf::Vector2f(100, 260), sf::Vector2f(100, 50), "Start", pixel_font);
    start_button.setCallback([](sf::RenderWindow& win) {
        //win.clear();
        win.close();
    });

    menu_window.create(sf::VideoMode(WIDTH, HEIGHT), "MENU", sf::Style::Close);

    while (menu_window.isOpen())
    {
        sf::Event event;
        while (menu_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                menu_window.close();
                info[2] = 1; // closed manually bit
            }
            //myButton.handleEvent(event);
            matrix_input.handleEvent(event);
            cond_input.handleEvent(event);
            start_button.handleEvent(event, menu_window);
        }

        menu_window.clear(sf::Color::Black);
        matrix_input.draw(menu_window);
        matrix_label.draw(menu_window);

        cond_input.draw(menu_window);
        cond_label.draw(menu_window);

        start_button.draw(menu_window);
        //board->setup();
        //myButton.draw(window);
        menu_window.display();
    }

    //int* info = new int[2];
    info[0] = std::stoi(matrix_input.getText()); // board size
    info[1] = std::stoi(cond_input.getText()); // win condition size
    return info;
    //std::cout << matrix_input.getText() << std::endl;
}

GameState game(int* game_info){
    if(game_info[2] == 1)
        return GameState::ONGOING;

    sf::RenderWindow game_window;
    game_window.setFramerateLimit(1);

    uint8_t size = game_info[0];
    uint8_t win_cond = game_info[1];
    //std::cout << game_info[0] << std::endl;
    //std::cout << game_info[1] << std::endl;

    Board* board = new Board(&game_window, size, win_cond);
    GameManager* manager = new GameManager(board);

    //game_window.create(sf::VideoMode(WIDTH*2, HEIGHT), "amogus", sf::Style::Close);
    game_window.create(sf::VideoMode(board->get_size() * TILE_SIZE
        , board->get_size() * TILE_SIZE), "TIC TAC TOE", sf::Style::Close);

    while (game_window.isOpen())
    {
        sf::Event event;
        while (game_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game_window.close();

            if(event.type == sf::Event::MouseButtonPressed)
                if(event.mouseButton.button == sf::Mouse::Left)
                    manager->handle_click(game_window, event.mouseButton.x, event.mouseButton.y);
        }
        game_window.clear(sf::Color::Black);
        
        board->setup();
        board->draw();

        game_window.display();
        // if(!manager->get_turn() && manager->get_state() == GameState::ONGOING)
        //     try{
        //         manager->ai(game_window);
        //     }catch(std::exception ignored){

        //     }
    }

    return manager->get_state();
}

void end(GameState result){
    if(result == GameState::ONGOING)
        return;

    // Creation of window and it's settings
    sf::RenderWindow end_window;

    // Matrix setup
    Label result_label(100, 25, "TEXT", pixel_font, 32);
    if(result == GameState::PLAYER_WON){
        result_label.set_text("PLAYER WON");
        result_label.set_pos(50, 25);
    }else if(result == GameState::AI_WON){
        result_label.set_text("AI WON");
    }else{
        result_label.set_text("DRAW");
    }

    // Start game button
    Button start_button(sf::Vector2f(100, 260), sf::Vector2f(100, 50), "Close", pixel_font);
    start_button.setCallback([](sf::RenderWindow& win) {
        //win.clear();
        win.close();
    });

    end_window.create(sf::VideoMode(WIDTH, HEIGHT), "RESULT", sf::Style::Close);

    while (end_window.isOpen())
    {
        sf::Event event;
        while (end_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                end_window.close();

            start_button.handleEvent(event, end_window);
        }

        end_window.clear(sf::Color::Black);
        result_label.draw(end_window);

        start_button.draw(end_window);
        //board->setup();
        //myButton.draw(window);
        end_window.display();
    }

}


int main()
{
    // Font setup
    pixel_font.loadFromFile("../fonts/pixel.ttf");

    // Main menu and game loop
    int* game_info = menu();
    GameState result = game(game_info);
    end(result);

    //end(true);
    return 0;
}