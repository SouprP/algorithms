#ifndef LOGIC_H_
#define LOGIC_H_

#include <core/board.h>
#include <iostream>

#include <core/pieces/x_piece.hpp>
#include <core/pieces/o_piece.hpp>

enum GameState{
    PLAYER_WON,
    AI_WON,
    DRAW
};

class GameManager{
    Board* board;

    bool player_turn;
    GameState state;

    public:
        GameManager(Board* board);

        void handle_click(sf::RenderWindow& win, int x, int y);
        bool is_winner(PieceType type);
        bool is_full();
        GameState get_state();
        void ai();
};

#endif