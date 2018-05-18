#ifndef LEETCODE_VALID_SUDOKU_H
#define LEETCODE_VALID_SUDOKU_H

#include <stdbool.h>

/**
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules (http://sudoku.com.au/TheRules.aspx).
 *
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *
 *
 * A partially filled sudoku which is valid.
 *
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */
bool isValidSudoku_36(char **board, int boardRowSize, int boardColSize);

#endif //LEETCODE_VALID_SUDOKU_H
