#include <core/algorithm.h>

Algorithm::Algorithm(){
    this->iters = 0;
}

int Algorithm::min_max(Board* board, int depth, bool isMaximizing){
    // min max implementation here
    int score = evaluate(board);

    if(score == 10 || score == -10 || depth == 0 || board->is_full())
        return score + depth;

    iters++;
    //sf::sleep(sf::microseconds(100));

    if(isMaximizing){
        int best = MIN_INF;

        // loop through all moves
        for(auto move : get_moves(board)){
            int y = move.first;
            int x = move.second;

            // make the move
            board->add_piece(new O_Piece(y, x));

            // recurse call min_max and choose max value
            best = std::max(best, min_max(board, depth - 1, false));

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
            best = std::min(best, min_max(board, depth - 1, true));

            // undo the move
            board->remove_piece(y, x);
        }
        return best;
    }
}

bool Algorithm::moves_left(Board* board){
    for(int y = 0; y < board->get_size(); y++)
        for(int x = 0; x < board->get_size(); x++)
            if(board->get_piece(x, y) == nullptr)
                return true;
    
    return false;
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

    if(board->is_winner(PieceType::O))
        return MAX_INF;

    // min_inf might be causing trouble
    if(board->is_winner(PieceType::X))
        return MIN_INF;
        //return MIN_INF;

    int size = board->get_size();
    int win_cond = board->get_win_cond();

    int score = 0;

    // heuristic based evaluation
    // checking rows, columns and diagonals for potential wins
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (board->get_piece(x, y) != nullptr) {
                // check for AI potential
                if (board->get_piece(x, y)->get_type() == PieceType::O) {
                    if (y < size - win_cond + 1 && x < size - win_cond + 1) {
                        // diagonal to bottom right
                        int count = 0;
                        for (int i = 0; i < win_cond; i++) {
                            if (board->get_piece(x + i, y + i) != nullptr &&
                                board->get_piece(x + i, y + i)->get_type() == PieceType::O) {
                                count++;
                            }
                        }
                        if (count == win_cond - 1) score += 100; // potential win
                        if (count == win_cond - 2) score += 10;
                    }
                    if (y >= win_cond - 1 && x < size - win_cond + 1) {
                        // diagonal to top right
                        int count = 0;
                        for (int i = 0; i < win_cond; i++) {
                            if (board->get_piece(x + i, y - i) != nullptr &&
                                board->get_piece(x + i, y - i)->get_type() == PieceType::O) {
                                count++;
                            }
                        }
                        if (count == win_cond - 1) score += 100; // potential win
                        if (count == win_cond - 2) score += 10;
                    }
                    if (x < size - win_cond + 1) {
                        // horizontal
                        int count = 0;
                        for (int i = 0; i < win_cond; i++) {
                            if (board->get_piece(x + i, y) != nullptr &&
                                board->get_piece(x + i, y)->get_type() == PieceType::O) {
                                count++;
                            }
                        }
                        if (count == win_cond - 1) score += 100; // potential win
                        if (count == win_cond - 2) score += 10;
                    }
                    if (y < size - win_cond + 1) {
                        // vertical
                        int count = 0;
                        for (int i = 0; i < win_cond; i++) {
                            if (board->get_piece(x, y + i) != nullptr &&
                                board->get_piece(x, y + i)->get_type() == PieceType::O) {
                                count++;
                            }
                        }
                        if (count == win_cond - 1) score += 100; // potential win
                        if (count == win_cond - 2) score += 10;
                    }
                }
                // check for opponent potential
                else if (board->get_piece(x, y)->get_type() == PieceType::X) {
                    if (y < size - win_cond + 1 && x < size - win_cond + 1) {
                        // diagonal to bottom right
                        int count = 0;
                        for (int i = 0; i < win_cond; i++) {
                            if (board->get_piece(x + i, y + i) != nullptr &&
                                board->get_piece(x + i, y + i)->get_type() == PieceType::X) {
                                count++;
                            }
                        }
                        if (count == win_cond - 1) score -= 100; // Potential loss
                        if (count == win_cond - 2) score -= 10;
                    }
                    if (y >= win_cond - 1 && x < size - win_cond + 1) {
                        // diagonal to top right
                        int count = 0;
                        for (int i = 0; i < win_cond; i++) {
                            if (board->get_piece(x + i, y - i) != nullptr &&
                                board->get_piece(x + i, y - i)->get_type() == PieceType::X) {
                                count++;
                            }
                        }
                        if (count == win_cond - 1) score -= 100; // Potential loss
                        if (count == win_cond - 2) score -= 10;
                    }
                    if (x < size - win_cond + 1) {
                        // horizontal
                        int count = 0;
                        for (int i = 0; i < win_cond; i++) {
                            if (board->get_piece(x + i, y) != nullptr &&
                                board->get_piece(x + i, y)->get_type() == PieceType::X) {
                                count++;
                            }
                        }
                        if (count == win_cond - 1) score -= 100; // potential loss
                        if (count == win_cond - 2) score -= 10;
                    }
                    if (y < size - win_cond + 1) {
                        // vertical
                        int count = 0;
                        for (int i = 0; i < win_cond; i++) {
                            if (board->get_piece(x, y + i) != nullptr &&
                                board->get_piece(x, y + i)->get_type() == PieceType::X) {
                                count++;
                            }
                        }
                        if (count == win_cond - 1) score -= 100; // potential loss
                        if (count == win_cond - 2) score -= 10;
                    }
                }
            }
        }
    }

    // int center = size / 2;
    // for (int y = 0; y < size; y++) {
    //     for (int x = 0; x < size; x++) {
    //         if (board->get_piece(x, y) != nullptr) {
    //             if (board->get_piece(x, y)->get_type() == PieceType::O) {
    //                 score += 5 * (size - std::max(std::abs(center - x), std::abs(center - y)));
    //             } else if (board->get_piece(x, y)->get_type() == PieceType::X) {
    //                 score -= 5 * (size - std::max(std::abs(center - x), std::abs(center - y)));
    //             }
    //         }
    //     }
    // }

    return score;
}

int Algorithm::get_iters(){
    return iters;
}

void Algorithm::reset_iters(){
    this->iters = 0;
}

int Algorithm::alpha_beta(Board* board, int depth, int alpha, int beta, bool isMaximizing){
    int score = evaluate(board);

    // If a terminal state is reached or depth is 0, return the evaluated score
    if (score == MAX_INF || score == MIN_INF || depth == 0 || board->is_full()) {
        return score;
    }

    //if(!moves_left(board))
    //    return 0;
    //sf::sleep(sf::milliseconds(100));

    iters++;

    if (isMaximizing) {
        int best = MIN_INF;

        for (auto move : get_moves(board)) {
            int y = move.first;
            int x = move.second;

            board->add_piece(new O_Piece(y, x));
            best = std::max(best, alpha_beta(board, depth - 1, alpha, beta, false));
            board->remove_piece(y, x);

            alpha = std::max(alpha, best);
            if (beta <= alpha)
                break;
        }
        return best;
    } else {
        int best = MAX_INF;

        for (auto move : get_moves(board)) {
            int y = move.first;
            int x = move.second;

            board->add_piece(new X_Piece(y, x));
            best = std::min(best, alpha_beta(board, depth - 1, alpha, beta, true));
            board->remove_piece(y, x);

            beta = std::min(beta, best);
            if (beta <= alpha)
                break;
        }
        return best;
    }
}