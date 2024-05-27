#include <core/logic.h>

GameManager::GameManager(Board* board){
    this->state = GameState::ONGOING;
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

    board->draw();
    win.display();
    // else{
    //     Piece* p = new O_Piece(grid_y, grid_x);
    //     board->add_piece(p);
    //     player_turn = true;
    // }

    if(board->is_winner(PieceType::X)){
        std::cout << "WON X" << std::endl;
        state = GameState::PLAYER_WON;
        win.close();
        return;
    }

    if(board->is_full()){
        std::cout << "DRAW" << std::endl;
        state = GameState::DRAW;
        win.close();
        return;
    }

    try{
        ai(win);
    }catch(std::exception ignored){

    }
}

GameState GameManager::get_state(){
    return this->state;
}

// true if player turn
bool GameManager::get_turn(){
    return this->player_turn;
}

void GameManager::ai(sf::RenderWindow& win) {
    // auto [best_y, best_x] = find_best_move(board, PieceType::O, PieceType::X, board->get_win_cond());
    // board->add_piece(new O_Piece(best_y, best_x));
    //Board* board_copy = board;
    //std::memcpy(board_copy, board, sizeof(board));

    int best_val = MIN_INF;
    int best_y = 0;
    int best_x = 0;

    int alfa = MIN_INF;
    int beta = MAX_INF;

    for(auto move : get_moves(board)){
        int y = move.first;
        int x = move.second;

        board->add_piece(new O_Piece(y, x));
        int move_val = min_max(board, 0, alfa, beta, false);
        board->remove_piece(y, x);

        if(move_val > best_val){
            best_y = y;
            best_x = x;
            best_val = move_val;
        }
    }

    if(best_y != -1 && best_x != -1){
        std::cout << "piece added!" << std::endl;
        board->add_piece(new O_Piece(best_y, best_x));
        player_turn = true;
    }
    // std::cout << "lol?" << std::endl;
    // for(auto obj : get_moves(board_copy)){
    //     std::cout << "Y: " << obj.first
    //         << ",  X: " << obj.second << std::endl;
    // }

    if (board->is_winner(PieceType::O)) {
        std::cout << "WON O" << std::endl;
        state = GameState::AI_WON;
        win.close();
    } else if (board->is_full()) {
        std::cout << "DRAW" << std::endl;
        state = GameState::DRAW;
        win.close();
    }
}