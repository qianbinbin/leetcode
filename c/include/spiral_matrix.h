/*
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 * Example 2:
 *
 *
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 * Constraints:
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 */

#ifndef LEETCODE_SPIRAL_MATRIX_H
#define LEETCODE_SPIRAL_MATRIX_H

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *spiralOrder_54_1(int **matrix, int matrixSize, int *matrixColSize,
                      int *returnSize);

#endif //LEETCODE_SPIRAL_MATRIX_H
