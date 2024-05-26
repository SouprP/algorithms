#ifndef PIECE_H_
#define PIECE_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>


#define O_TEXTURE "../images/O_PIECE.png"
#define X_TEXTURE "../images/X_PIECE.png"

enum PieceType{
    O,
    X,    
};


class Piece{
    protected:
        PieceType piece_type;

        uint8_t pos_x;
        uint8_t pos_y;

        sf::Vector2i pos;
        sf::Sprite* sprite;
        sf::Texture* texture;

        //virtual void load_texture() = 0;
        void load_texture(){
            if(piece_type == PieceType::O)
                texture->loadFromFile(O_TEXTURE);
            else
                texture->loadFromFile(X_TEXTURE);
            
            // texture settings
            texture->setSmooth(true);

            // apply texture to sprite
            //sprite = new sf::Sprite(*texture);
            sprite->setTexture(*texture);
        }

    public:
        Piece(uint8_t pos_y, uint8_t pos_x, PieceType piece_type){
            this->piece_type = piece_type;
            this->sprite = new sf::Sprite();
            this->texture = new sf::Texture();
            this->pos_x = pos_x;
            this->pos_y = pos_y;
        }

        virtual int get_weight() = 0;
        virtual sf::Sprite* get_sprite() = 0;

        uint8_t get_x(){ return pos_x;}
        uint8_t get_y(){ return pos_y;}

        PieceType get_type(){ return piece_type;}
};

#endif