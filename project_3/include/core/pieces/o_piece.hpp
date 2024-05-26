#include <core/interface/piece.h>

class O_Piece : public Piece{
    public:
        O_Piece(uint8_t pos_y, uint8_t pos_x)
            : Piece(pos_y, pos_x, PieceType::O){
                load_texture();
            }

        int get_weight() override{
            return 10;
        }

        sf::Sprite* get_sprite() override{
            return sprite;
        }
        
};