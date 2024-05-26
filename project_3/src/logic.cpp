#include <core/logic.h>

GameManager::GameManager(Board* board){
    this->board = board;
    this->player_turn = true;
}

void GameManager::run(sf::RenderWindow& win){

}

void GameManager::handle_click(int x, int y){
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
        //player_turn = false;
    }

    if(board->is_winner(PieceType::X))
        std::cout << "WON" << std::endl;

    // std::cout << "clicked n! X: " << x 
    //     << ",  Y: " << y << std::endl;
    std::cout << "clicked! X: " << grid_x 
        << ",  Y: " << grid_y << std::endl;
}