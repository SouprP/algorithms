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
    // else{
    //     Piece* p = new O_Piece(grid_y, grid_x);
    //     board->add_piece(p);
    //     player_turn = true;
    // }

    if(board->is_winner(PieceType::X)){
        std::cout << "WON X" << std::endl;
        state = GameState::PLAYER_WON;
        win.close();
        
    }
    // else if(board->is_winner(PieceType::O)){
    //     std::cout << "WON O" << std::endl;
    //     state = GameState::AI_WON;
    //     win.close();
    // }

    if(board->is_full()){
        std::cout << "DRAW" << std::endl;
        state = GameState::DRAW;
        win.close();
    }

    // std::cout << "clicked n! X: " << x 
    //     << ",  Y: " << y << std::endl;
    // std::cout << "clicked! X: " << grid_x 
    //     << ",  Y: " << grid_y << std::endl;
    ai(win);
}

// returns true if player won (X_PIECE)
// bool GameManager::get_winner(){
//     return player_turn;
// }

GameState GameManager::get_state(){
    return this->state;
}

// min-max algorithm
int GameManager::minimax(Board* board, uint8_t depth, bool isMaximizingPlayer, PieceType aiType, PieceType playerType){
    if (board->is_winner(aiType)) {
        return 10 - depth;
    }
    if (board->is_winner(playerType)) {
        return depth - 10;
    }
    if (board->is_full()) {
        return 0;
    }

    if (isMaximizingPlayer) {
        int bestScore = -1000;
        for (uint8_t y = 0; y < board->get_size(); ++y) {
            for (uint8_t x = 0; x < board->get_size(); ++x) {
                if (board->get_piece(y, x) == nullptr) {
                    board->add_piece(new X_Piece(y, x)); // AI's move
                    int score = minimax(board, depth + 1, false, aiType, playerType);
                    board->remove_piece(y, x); // Undo move
                    bestScore = std::max(score, bestScore);
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (uint8_t y = 0; y < board->get_size(); ++y) {
            for (uint8_t x = 0; x < board->get_size(); ++x) {
                if (board->get_piece(y, x) == nullptr) {
                    board->add_piece(new O_Piece(y, x)); // Player's move
                    int score = minimax(board, depth + 1, true, aiType, playerType);
                    board->remove_piece(y, x); // Undo move
                    bestScore = std::min(score, bestScore);
                }
            }
        }
        return bestScore;
    }
}

std::pair<uint8_t, uint8_t> GameManager::find_best_move(Board* board, PieceType aiType, PieceType playerType){
    int bestScore = -1000;
    std::pair<uint8_t, uint8_t> bestMove;

    for (uint8_t y = 0; y < board->get_size(); ++y) {
        for (uint8_t x = 0; x < board->get_size(); ++x) {
            if (board->get_piece(y, x) == nullptr) {
                board->add_piece(new X_Piece(y, x)); // AI's move
                int score = minimax(board, 0, false, aiType, playerType);
                board->remove_piece(y, x); // Undo move

                if (score > bestScore) {
                    bestScore = score;
                    bestMove = std::make_pair(y, x);
                }
            }
        }
    }

    return bestMove;
}

void GameManager::ai(sf::RenderWindow& win){
    auto [best_y, best_x] = find_best_move(board, PieceType::X, PieceType::O);
    board->add_piece(new X_Piece(best_y, best_x));
    player_turn = true;

    if(board->is_winner(PieceType::O)){
        std::cout << "WON O" << std::endl;
        state = GameState::AI_WON;
        win.close();
    }

    if(board->is_full()){
        std::cout << "DRAW" << std::endl;
        state = GameState::DRAW;
        win.close();
    }
}