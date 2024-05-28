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
    Algorithm alg = Algorithm();

    // find the best move for O_Piece
    int best_val = MIN_INF;
    std::pair<int, int> best_move = {-1, -1};

    for (auto move : alg.get_moves(board)) {
        int y = move.first;
        int x = move.second;

        // Make the move
        board->add_piece(new O_Piece(y, x));

        // Compute evaluation function for this move
        int moveVal = alg.min_max(board, MAX_DEPTH, false);

        // Undo the move
        board->remove_piece(y, x);

        // If the value of the current move is more than the best value, update best
        if (moveVal > best_val) {
            best_move = { y, x };
            best_val = moveVal;
        }
    }

    // Make the best move
    board->add_piece(new O_Piece(best_move.first, best_move.second));
    board->draw();
    win.display();

    std::cout << "Iterations: " << alg.get_iters() << std::endl;
    alg.reset_iters();

    // Update game state after AI move
    if (board->is_winner(PieceType::O)) {
        std::cout << "WON O" << std::endl;
        state = GameState::AI_WON;
        win.close();
    } else if (board->is_full()) {
        std::cout << "DRAW" << std::endl;
        state = GameState::DRAW;
        win.close();
    }

    player_turn = true;
}