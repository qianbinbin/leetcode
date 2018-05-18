#ifndef LEETCODE_PASCALS_TRIANGLE_H
#define LEETCODE_PASCALS_TRIANGLE_H

/**
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 *
 * https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly above it.
 *
 * Example:
 *
 * Input: 5
 * Output:
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 *
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate_118(int numRows, int **columnSizes);

#endif //LEETCODE_PASCALS_TRIANGLE_H
