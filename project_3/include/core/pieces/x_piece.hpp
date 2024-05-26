#include <core/interface/piece.h>

class X_Piece : public Piece{
    public:
        X_Piece(uint8_t pos_y, uint8_t pos_x)
            : Piece(pos_y, pos_x, PieceType::X){
                load_texture();
            }

        int get_weight() override{
            return 10;
        }

        sf::Sprite* get_sprite() override{
            return sprite;
        }
        
};