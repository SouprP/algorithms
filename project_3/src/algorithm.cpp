#include <core/algorithm.h>

int min_max_util(Board* board, int depth, int alpha, int beta, bool isMaxizing){
    int score = evaluate(board);
    std::cout << "depth: " << depth << std::endl;

    if(score == 10 || score == -10 || depth == MAX_DEPTH){
        return score;
    }

    if(board->is_full())
        return 0;

    //iters++;
    Piece* piece = nullptr;
    if(isMaxizing){
        //int best_val = -1000;
        int best_val = MIN_INF;
        for(auto move : get_moves(board)){
            int y = move.first;
            int x = move.second;

            try{
            std::cout << "Trying move O at (" << y << ", " << x << ")" << std::endl;
            piece = new O_Piece(y, x);
            board->add_piece(piece);
            best_val = std::max(best_val, min_max_util(board, depth + 1, alpha, beta, false));

            board->remove_piece(y, x);
            //delete piece;
            alpha = std::max(alpha, best_val);

            if(beta <= alpha)
                break;
            }catch(std::exception){
                std::cout << "error when y: " << y << ", x: " << x << std::endl;
            }
        }

        return best_val;
    }

    //int best_val = 1000;
    int best_val = MAX_INF;
    for(auto move : get_moves(board)){
        int y = move.first;
        int x = move.second;

        try{
        std::cout << "Trying move X at (" << y << ", " << x << ")" << std::endl;
        piece = new X_Piece(y, x);
        board->add_piece(piece);
        best_val = std::min(best_val, min_max(board, depth + 1, alpha, beta, true));

        board->remove_piece(y, x);
        //delete piece;
        alpha = std::min(alpha, best_val);

        if(beta <= alpha)
            break;

        }catch(std::exception){
                std::cout << "error when y: " << y << ", x: " << x << std::endl;
        }
    }

    return best_val;
}

int min_max(Board* board, int depth, int alpha, int beta, bool isMaxizing){
    //iters = 0;
    int result = min_max_util(board, depth, alpha, beta, isMaxizing);

    //std::cout << "Iterations: " << iters << std::endl;
    return result;
}

std::vector<std::pair<int, int>> get_moves(Board* board){
    std::vector<std::pair<int, int>> moves;
    for(int y = 0; y < board->get_size() - 1; y++)
        for(int x = 0; x < board->get_size() - 1; x++)
            if(board->get_piece(x, y) == nullptr)
                moves.push_back({y, x});

    return moves;
}

int evaluate(Board* board){
    // AI winning
    if(board->is_winner(PieceType::O))
        return 10;

    // Player winning
    if(board->is_winner(PieceType::X))
        return -10;

    return 0;
}