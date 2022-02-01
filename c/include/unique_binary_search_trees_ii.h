/*
 * Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
 *
 *
 *
 * Example 1:
 * https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg
 *
 * Input: n = 3
 * Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 *
 * Example 2:
 *
 * Input: n = 1
 * Output: [[1]]
 *
 *
 * Constraints:
 *
 * 1 <= n <= 8
 */

#ifndef LEETCODE_UNIQUE_BINARY_SEARCH_TREES_II_H
#define LEETCODE_UNIQUE_BINARY_SEARCH_TREES_II_H

#include "common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode **generateTrees_95_1(int n, int *returnSize);

#endif //LEETCODE_UNIQUE_BINARY_SEARCH_TREES_II_H
