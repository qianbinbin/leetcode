/*
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 *
 * Example:
 *
 * Input:
 * [
 *   ["1","0","1","0","0"],
 *   ["1","0","1","1","1"],
 *   ["1","1","1","1","1"],
 *   ["1","0","0","1","0"]
 * ]
 * Output: 6
 */

#ifndef LEETCODE_MAXIMAL_RECTANGLE_H
#define LEETCODE_MAXIMAL_RECTANGLE_H

int maximalRectangle_85_1(char **matrix, int matrixRowSize, int matrixColSize);

int maximalRectangle_85_2(char **matrix, int matrixRowSize, int matrixColSize);

#endif //LEETCODE_MAXIMAL_RECTANGLE_H
