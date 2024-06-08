#ifndef LOGIC_H_
#define LOGIC_H_

#include <core/board.h>
#include <core/algorithm.h>
#include <iostream>
#include <random>

#include <core/pieces/x_piece.hpp>
#include <core/pieces/o_piece.hpp>

//#define MAX_DEPTH 5

enum GameState{
    ONGOING,
    PLAYER_WON,
    AI_WON,
    DRAW
};

class GameManager{
    Board* board;

    int depth;
    bool player_turn;
    GameState state;

    public:
        GameManager(Board* board);

        void handle_click(sf::RenderWindow& win, int x, int y);
        bool is_winner(PieceType type);
        bool is_full();
        bool get_turn();
        GameState get_state();
        void set_depth(int depth);

        void ai(sf::RenderWindow& win);
        void ai_alpha(sf::RenderWindow& win);

        // min-max algorithm
};

#endif