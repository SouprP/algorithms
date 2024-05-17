#ifndef PIECE_H_
#define PIECE_H_

#include <SFML/Graphics.hpp>
#include <stdio.h>

enum PieceType{
    KING,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN
};

enum PieceColor{
    WHITE,
    BLACK
};

class Piece{
    protected:
        PieceType piece_type;
        PieceColor piece_color;

        int pos_x;
        int pos_y;

        sf::Vector2i pos;
        sf::Sprite sprite;
        sf::Texture texture;

        virtual void load_texture() = 0;

    public:
        virtual void move() = 0;
        virtual int get_weight() = 0;
};

#endif