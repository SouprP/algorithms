#ifndef BISHOP_HPP_
#define BISHOP_HPP_

#include <core/interface/piece.h>
#include <iostream>

#define W_TEXTURE "../images/w_bishop.png"
#define B_TEXTURE "../images/b_bishop.png"
#define WEIGHT 300

class Bishop : public Piece{
    public:
        //Bishop(sf::RenderWindow* win, PieceColor piece_color){
        Bishop(uint8_t pos_y, uint8_t pos_x, PieceColor piece_color) 
            : Piece(pos_y, pos_x, piece_color){
                load_texture(W_TEXTURE, B_TEXTURE);
        }

        void move() override{

        }

        int get_weight() override{
            return WEIGHT;
        }

        sf::Sprite* get_sprite() override{
            return sprite;
        }

        std::string get_name() override{
            return "bishop";
        }

};



#endif