#ifndef PIECE_H_
#define PIECE_H_

#include <SFML/Graphics.hpp>
#include <iostream>
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

enum MoveType{
    VERTICAL_ONE,
    VERTICAL_TWO,
    HORIZONTAL_ALL,
    VERTICAL_ALL,
    DIAGONAL
};

class Piece{
    protected:
        PieceType piece_type;
        PieceColor piece_color;

        uint8_t pos_x;
        uint8_t pos_y;

        sf::Vector2i pos;
        sf::Sprite* sprite;
        sf::Texture* texture;

        //virtual void load_texture() = 0;
        void load_texture(std::string W_TEXTURE, std::string B_TEXTURE){
            //texture = new sf::Texture();

            if(piece_color == PieceColor::WHITE)
                texture->loadFromFile(W_TEXTURE);
            else
                texture->loadFromFile(B_TEXTURE);
            
            // texture settings
            texture->setSmooth(true);

            // apply texture to sprite
            //sprite = new sf::Sprite(*texture);
            sprite->setTexture(*texture);
        }

    public:
        Piece(uint8_t pos_y, uint8_t pos_x, PieceColor piece_color){
            this->piece_color = piece_color;
            this->sprite = new sf::Sprite();
            this->texture = new sf::Texture();
            this->pos_x = pos_x;
            this->pos_y = pos_y;
        }

        virtual void move() = 0;
        virtual int get_weight() = 0;
        virtual sf::Sprite* get_sprite() = 0;
        virtual std::string get_name() = 0;

        uint8_t get_x(){ return pos_x;}
        uint8_t get_y(){ return pos_y;}
};

#endif