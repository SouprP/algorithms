#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <stdint.h>

#include <core/pieces/bishop.hpp>
#include <core/interface/piece.h>

#define BOARD_FILE "../images/board_480px.png"

#define X_OFFSET 480
#define Y_OFFSET 25
#define TILE_SIZE 60

class Board{
    /**
     *      
     *      0 R KN B Q K B KN R
     *      1 P P  P P P P P P
     *      2
     *      3
     *      4
     *      5
     *      6
     *      7
    */
    private:
        sf::RenderWindow* win;
        sf::Texture b_texture;
        sf::Sprite b_sprite;

        Piece* board[8][8] = {nullptr};
        //sf::RectangleShape tiles[8][8];
        std::vector<Piece*> pieces;

        void apply_pieces();
    
    public:
        Board(sf::RenderWindow* win);

        // basic starting setup
        void setup();
        void setup_pieces();
        void setup_pieces(bool isBlack);

        void draw();
};

#endif