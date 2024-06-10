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
    // else{
    //     Piece* p = new O_Piece(grid_y, grid_x);
    //     board->add_piece(p);
    //     player_turn = true;
    // }

    win.clear();
    board->setup();
    board->draw();
    win.display();

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
        //ai_alpha(win);
    }catch(std::exception& ignored){
        std::cout << ignored.what() << std::endl;
    }
}

GameState GameManager::get_state(){
    return this->state;
}

// true if player turn
bool GameManager::get_turn(){
    return this->player_turn;
}

void GameManager::set_depth(int depth){
    this->depth = depth;
}

void GameManager::ai(sf::RenderWindow& win) {
    Algorithm alg = Algorithm();

    // find the best move for O_Piece
    int best_val = MIN_INF;
    std::pair<int, int> best_move = {-1, -1};

    if(alg.moves_left(board))
        for (auto move : alg.get_moves(board)) {
            int y = move.first;
            int x = move.second;

            // Make the move
            board->add_piece(new O_Piece(y, x));

            // Compute evaluation function for this move
            int moveVal = alg.min_max(board, MAX_DEPTH, false);

            // Undo the move
            board->remove_piece(y, x);

            // update the value if it's better
            if (moveVal > best_val) {
                best_move = { y, x };
                best_val = moveVal;
            }
        }

    // making the move
    if(best_move.first < 0 && best_move.second < 0){
        auto moves = alg.get_moves(board);
        
        srand(time(NULL));
        int random = rand() % moves.size();

        best_move = moves[random];
        //std::cout << "Random y: " << moves[random].first
        //    << "random x: " << moves[random].second << std::endl; 
    }

    board->add_piece(new O_Piece(best_move.first, best_move.second));
    win.clear();
    board->setup();
    board->draw();
    win.display();

    std::cout << "Best val: " << best_val << std::endl;
    std::cout << "Iterations: " << alg.get_iters() << std::endl;
    alg.reset_iters();

    if (board->is_winner(PieceType::O)) {
        std::cout << "WON O" << std::endl;
        state = GameState::AI_WON;
        win.close();
        return;
    } else if (board->is_full()) {
        std::cout << "DRAW" << std::endl;
        state = GameState::DRAW;
        win.close();
        return;
    }

    player_turn = true;
}

void GameManager::ai_alpha(sf::RenderWindow& win){
    Algorithm alg;

    int best_val = MIN_INF;
    std::pair<int, int> best_move = { -1, -1 };

    // finding the best move
    for (auto move : alg.get_moves(board)) {
        int y = move.first;
        int x = move.second;

        board->add_piece(new O_Piece(y, x));
        int move_val = alg.alpha_beta(board, depth, MIN_INF, MAX_INF, false);
        //int move_val = alg.min_max(board, depth, false);
        board->remove_piece(y, x);

        if (move_val > best_val) {
            best_move = { y, x };
            best_val = move_val;
        }
    }

    if(best_move.first < 0 && best_move.second < 0){
        auto moves = alg.get_moves(board);
        
        srand(time(NULL));
        int random = rand() % moves.size();

        best_move = moves[random];
        //std::cout << "Random y: " << moves[random].first
        //    << "random x: " << moves[random].second << std::endl; 
    }

    board->add_piece(new O_Piece(best_move.first, best_move.second));
    win.clear();
    board->setup();
    board->draw();
    win.display();

    std::cout << "Best val: " << best_val << std::endl;
    std::cout << "Iterations: " << alg.get_iters() << std::endl;
    alg.reset_iters();

    if (board->is_winner(PieceType::O)) {
        std::cout << "WON O" << std::endl;
        state = GameState::AI_WON;
        win.close();
        return;
    } else if (board->is_full()) {
        std::cout << "DRAW" << std::endl;
        state = GameState::DRAW;
        win.close();
        return;
    }

    player_turn = true;
}