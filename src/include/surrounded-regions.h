#ifndef LEETCODE_SURROUNDED_REGIONS_H
#define LEETCODE_SURROUNDED_REGIONS_H

/**
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *
 * For example,
 *
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 *
 * After running your function, the board should be:
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 */

/**
 * Depth-first search
 */
void solve_130_1(char **board, int boardRowSize, int boardColSize);

/**
 * Breadth-first search, time limit exceeded
 */
void solve_130_2(char **board, int boardRowSize, int boardColSize);

#endif //LEETCODE_SURROUNDED_REGIONS_H
