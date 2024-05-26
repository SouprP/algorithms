#ifndef LOGIC_H_
#define LOGIC_H_

#include <core/board.h>
#include <iostream>

#include <core/pieces/x_piece.hpp>
#include <core/pieces/o_piece.hpp>

class GameManager{
    Board* board;

    bool player_turn;

    public:
        GameManager(Board* board);

        void run(sf::RenderWindow& win);
        void handle_click(int x, int y);
        bool is_winner(PieceType type);
        bool is_full();
        void ai();
};

#endif