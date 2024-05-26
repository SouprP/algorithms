#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <stdint.h>

#include <core/interface/piece.h>

#define BOARD_FILE "../images/board_480px.png"

#define TILE_1 "../images/TILE_1.png"
#define TILE_2 "../images/TILE_2.png"

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
        // Window and other
        sf::RenderWindow* win;
        uint8_t size, win_cond;

        // Board sprites and textures
        sf::Texture t1_texture, t2_texture;
        sf::Sprite t1_sprite, t2_sprite;

        Piece*** board;
        std::vector<Piece*> pieces;

        //bool player_turn;
    
    public:
        Board(sf::RenderWindow* win, uint8_t size, uint8_t win_cond);

        // basic starting setup
        void setup();

        void set_size(uint8_t size);
        uint8_t get_size();
        void add_piece(Piece* piece);
        Piece* get_piece(uint8_t x, uint8_t y);

        bool is_winner(PieceType type);
        bool is_full();

        void draw();
};

#endif