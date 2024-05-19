#include <core/board.hpp>


Board::Board(sf::RenderWindow* win){
    this->win = win;
}

void Board::setup(){
    b_texture.loadFromFile(BOARD_FILE);
    b_sprite.setTexture(b_texture);
    b_sprite.setPosition(X_OFFSET, Y_OFFSET);
    //board_s.setRotation(90);
    //board_s.setPosition(sf::Vector2f(board_s.getPosition().x + 480, 
    //    board_s.getPosition().y + 0));
    win->draw(b_sprite);
}

void Board::setup_pieces() {
    setup_pieces(false);
}

void Board::setup_pieces(bool isBlack){
    // for(uint8_t y = 0; y < 8; y++)
    //     for(uint8_t x = 0; x < 8; x++)
    //         board[y][x] = nullptr;

    if(isBlack){
        Piece* b_bishop_1 = new Bishop(7, 6 ,PieceColor::BLACK);
        Piece* w_bishop_1 = new Bishop(6, 6, PieceColor::WHITE);
        board[7][2] = b_bishop_1; 
        board[0][6] = w_bishop_1;

        apply_pieces();
        return;
    }

    Piece* b_bishop_1 = new Bishop(7, 6 ,PieceColor::BLACK);
        Piece* w_bishop_1 = new Bishop(6, 6, PieceColor::WHITE);
        board[5][6] = b_bishop_1; 
        board[2][6] = w_bishop_1;

        apply_pieces();
    //Piece* b_pawn_1

}

void Board::draw(){
    for(uint8_t y = 0; y < 8; y++)
        for(uint8_t x = 0; x < 8; x++)
            if(board[y][x] != nullptr){
                Piece* p = board[y][x];
                
                p->get_sprite()->setPosition(X_OFFSET + x * TILE_SIZE
                    , Y_OFFSET + y*TILE_SIZE);
                
                win->draw(*p->get_sprite());
                
            }
}

void Board::apply_pieces(){
    for(Piece* p : pieces)
        board[p->get_y()][p->get_x()] = p;
}
