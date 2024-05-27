#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include <core/board.h>
#include <core/logic.h>

#include <limits>
#include <vector>
#include <cstring>

#define MAX_DEPTH 3

#define MIN_INF std::numeric_limits<int>().min()
#define MAX_INF std::numeric_limits<int>().max()

//int iters = 0;

int min_max(Board* board, int depth, int alpha, int beta, bool isMaxizing);

int min_max_util(Board* board, int depth, int alpha, int beta, bool isMaxizing);

std::vector<std::pair<int, int>> get_moves(Board* board);

int evaluate(Board* board);

#endif