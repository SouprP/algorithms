#include <core/board.h>


Board::Board(sf::RenderWindow* win, uint8_t size, uint8_t win_cond){
    this->win = win;
    this->size = size;
    this->win_cond = win_cond;

    // setup the board as a set of nullptr
    this->board = new Piece**[size];
    for(uint8_t y = 0; y < size; y++){
        board[y] = new Piece*[size];
        for(uint8_t x = 0; x < size; x++)
            board[y][x] = nullptr;
    }
}

Board::~Board() {
    for (uint8_t y = 0; y < size; y++) {
        for (uint8_t x = 0; x < size; x++) {
            delete board[y][x]; // Delete each Piece
        }
        delete[] board[y]; // Delete each row
    }
    delete[] board; // Delete the board array
}

void Board::setup(){
    // Load textures
    t1_texture.loadFromFile(TILE_1);
    t2_texture.loadFromFile(TILE_2);

    // Apply textures
    //t1_sprite.setTexture(t1_texture);
    //t2_sprite.setTexture(t2_texture);


    for(uint8_t y = 0; y < size; y++)
        for(uint8_t x = 0; x < size; x++){
            sf::Sprite sprite = sf::Sprite();

            if((x+y) % 2 == 0)
                sprite.setTexture(t1_texture);
            else
                sprite.setTexture(t2_texture);

            sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
            win->draw(sprite);
        }
    //b_texture.loadFromFile(BOARD_FILE);
    //b_sprite.setTexture(b_texture);
    //b_sprite.setPosition(X_OFFSET, Y_OFFSET);
    
    //board_s.setRotation(90);
    //board_s.setPosition(sf::Vector2f(board_s.getPosition().x + 480, 
    //    board_s.getPosition().y + 0));
    
    //win->draw(b_sprite);
}

void Board::set_size(uint8_t size){
    this->size = size;
}

uint8_t Board::get_size(){
    return size;
}

bool Board::is_winner(PieceType type){
    // check each vertical row if is winner
    for(uint8_t y = 0; y < size; y++){
        uint8_t count = 0;
        for(uint8_t x = 0; x < size; x++){
            if(count == win_cond)
                return true;

            if(board[y][x] != nullptr){
                if(board[y][x]->get_type() == type)
                    count++;
                else
                    count = 0;
            }
            else
                count = 0;
        }

        if(count == win_cond)
            return true;
    }

    // check each horizontal row
    for(uint8_t x = 0; x < size; x++){
        uint8_t count = 0;
        for(uint8_t y = 0; y < size; y++){
            if(count == win_cond)
                return true;

            if(board[y][x] != nullptr){
                if(board[y][x]->get_type() == type)
                    count++;
                else
                    count = 0;
            }
            else
                count = 0;
        }

        if(count == win_cond)
            return true;
    }

    //diagonal check from the left
    for(uint8_t y = 0; y < size - win_cond + 1; y++)
        for(uint8_t x = 0; x < size; x++){
            uint8_t diag_y = y;
            uint8_t count = 0;
            for(uint8_t diag_x = x; diag_x < size
                && y < size - 1 ; diag_x++){
                if(count == win_cond)
                    return true;

                if(board[diag_y][diag_x] != nullptr){
                    if(board[diag_y][diag_x]->get_type() == type){
                        diag_y++;
                        count++;
                    }else
                        count = 0;
                }
                else
                    count = 0;
            }

            if(count == win_cond)
                return true;
        }

    // // diagonal check from the right
    for (uint8_t y = 0; y < size - win_cond + 1; y++) {
        for (uint8_t x = 0; x < size; x++) {
            uint8_t diag_y = y;
            uint8_t count = 0;
            for (int8_t diag_x = x; diag_x >= 0 && diag_y < size; diag_x--) {
                if (count == win_cond)
                    return true;

                if (board[diag_y][diag_x] != nullptr) {
                    if (board[diag_y][diag_x]->get_type() == type){
                        diag_y++;
                        count++;
                    }else
                        count = 0;
                } else
                    count = 0;
            }

            if (count == win_cond)
                return true;
        }
    }

    return false;
}

bool Board::is_full(){
    for (uint8_t y = 0; y < size; ++y)
        for (uint8_t x = 0; x < size; ++x)
            if (board[y][x] == nullptr)
                return false;
    return true;
}

uint8_t Board::get_win_cond(){
    return win_cond;
}

void Board::add_piece(Piece* piece){
    uint8_t x = piece->get_x();
    uint8_t y = piece->get_y();
    //board[piece->get_y()][piece->get_x()] = piece;
    //pieces.push_back(piece);
    if(x >= size || y>= size || board[y][x] != nullptr){
        delete piece;
        return;
    }

    board[y][x] = piece;
    //pieces.push_back(piece);
}

void Board::remove_piece(int y, int x){
    if(x >= size || y>= size || board[y][x] == nullptr)    
        return;

    delete board[y][x];
    board[y][x] = nullptr;
}

Piece* Board::get_piece(uint8_t x, uint8_t y){
    if(x >= size || y >= size)
        return nullptr;

    return board[y][x];
}

void Board::draw(){
    for(uint8_t y = 0; y < size; y++)
        for(uint8_t x = 0; x < size; x++)
            if(board[y][x] != nullptr){
                Piece* p = board[y][x];
                //std::cout << p->get_weight() << std::endl;
                p->get_sprite()->setPosition(x * TILE_SIZE
                    , y*TILE_SIZE);
                
                win->draw(*p->get_sprite());
                
            }
}

