#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include <core/board.h>
#include <core/logic.h>

#include <limits>
#include <vector>
#include <cstring>

#define MAX_DEPTH 5

#define MIN_INF INT32_MIN
#define MAX_INF INT32_MAX

//int iters = 0;
class Algorithm{
    private:
        int iters;

    public:
        Algorithm();

        int min_max(Board* board, int depth, bool isMaximizing);
        int alpha_beta(Board* board, int depth, int alpha, int beta, bool isMaximizing);
        
        bool moves_left(Board* board);
        std::vector<std::pair<int, int>> get_moves(Board* board);
        int evaluate(Board* board);

        int get_iters();
        void reset_iters();
};

#endif