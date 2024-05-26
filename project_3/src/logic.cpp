#include <core/logic.h>

GameManager::GameManager(Board* board){
    this->board = board;
    this->player_turn = true;
}

void GameManager::handle_click(sf::RenderWindow& win, int x, int y){
    int grid_x = x / TILE_SIZE;
    int grid_y = y / TILE_SIZE;

    if(grid_x >= board->get_size())
        return;

    if(grid_y >= board->get_size()) 
        return;

    if(board->get_piece(grid_x, grid_y) != nullptr)
        return;

    if(player_turn){
        Piece* p = new X_Piece(grid_y, grid_x);
        board->add_piece(p);
        player_turn = false;
    }
    else{
        Piece* p = new O_Piece(grid_y, grid_x);
        board->add_piece(p);
        player_turn = true;
    }

    if(board->is_winner(PieceType::X)){
        std::cout << "WON X" << std::endl;
        state = GameState::PLAYER_WON;
        win.close();
        
    }
    else if(board->is_winner(PieceType::O)){
        std::cout << "WON O" << std::endl;
        state = GameState::AI_WON;
        win.close();
    }

    if(board->is_full()){
        std::cout << "DRAW" << std::endl;
        state = GameState::DRAW;
        win.close();
    }

    // std::cout << "clicked n! X: " << x 
    //     << ",  Y: " << y << std::endl;
    // std::cout << "clicked! X: " << grid_x 
    //     << ",  Y: " << grid_y << std::endl;
}

// returns true if player won (X_PIECE)
// bool GameManager::get_winner(){
//     return player_turn;
// }

GameState GameManager::get_state(){
    return this->state;
}