#include <core/algorithm.h>

Algorithm::Algorithm(){
    this->iters = 0;
}

int Algorithm::min_max_util(Board* board, int depth, bool isMaxizing){
    // min max implementation here
    int score = evaluate(board);

    if(score == 10 || score == -10 || depth == 0 || board->is_full())
        return score;

    iters++;

    if(isMaxizing){
        int best = MIN_INF;

        // loop through all moves
        for(auto move : get_moves(board)){
            int y = move.first;
            int x = move.second;

            // make the move
            board->add_piece(new O_Piece(y, x));

            // recurse call min_max and choose max value
            best = std::max(best, min_max_util(board, depth - 1, false));

            // undo the move
            board->remove_piece(y, x);
        }
        return best;
    }else{
        int best = MAX_INF;

        // loop through all moves
        for(auto move : get_moves(board)){
            int y = move.first;
            int x = move.second;

            // make the move
            board->add_piece(new O_Piece(y, x));

            // recurse call min_max and choose min value
            best = std::min(best, min_max_util(board, depth - 1, true));

            // undo the move
            board->remove_piece(y, x);
        }
        return best;
    }
}

int Algorithm::min_max(Board* board, int depth, bool isMaxizing){
    //iters = 0;
    int result = min_max_util(board, depth, isMaxizing);

    //std::cout << "Iterations: " << iters << std::endl;
    return result;
}

std::vector<std::pair<int, int>> Algorithm::get_moves(Board* board){
    std::vector<std::pair<int, int>> moves;
    for(int y = 0; y < board->get_size(); y++)
        for(int x = 0; x < board->get_size(); x++)
            if(board->get_piece(x, y) == nullptr)
                moves.push_back({y, x});

    return moves;
}

int Algorithm::evaluate(Board* board){
    // AI winning
    if(board->is_winner(PieceType::O))
        return 10;

    // Player winning
    if(board->is_winner(PieceType::X))
        return -10;

    return 0;
}

int Algorithm::get_iters(){
    return iters;
}

void Algorithm::reset_iters(){
    this->iters = 0;
}