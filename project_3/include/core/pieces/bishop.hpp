#ifndef BISHOP_HPP_
#define BISHOP_HPP_

#include <core/interfaces/piece.h>
#include <iostream>

#define W_TEXTURE "../images/w_bishop.svg"
#define B_TEXTURE "../images/b_bishop.png"
#define WEIGHT 300

class Bishop : public Piece{
    private:
        void load_texture(){
            if(piece_color == PieceColor::WHITE)
                texture.loadFromFile(W_TEXTURE);
            else
                texture.loadFromFile(B_TEXTURE);
            
            // texture settings
            texture.setSmooth(true);

            // apply texture to sprite
            sprite.setTexture(texture);
        }

    public:
        Bishop(sf::RenderWindow* win){
            piece_color = PieceColor::BLACK;
            load_texture();
            win->draw(sprite);
        }

        void move() override{

        }

        int get_weight() override{
            return WEIGHT;
        }



    
} ;



#endif