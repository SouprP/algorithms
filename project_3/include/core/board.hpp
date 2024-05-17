#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <stdint.h>

#include <core/pieces/bishop.hpp>
#include <core/interfaces/piece.h>

class Board{
    private:
        //uint8_t board[8][8];
        sf::RectangleShape tiles[8][8];
        std::vector<Piece*> pieces;
        bool isFlipped;

        void rotate(){

        }
    
    public:
        void setup(){

        }
};

#endif