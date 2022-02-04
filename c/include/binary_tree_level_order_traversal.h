/*
 * Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
 *
 *
 *
 * Example 1:
 * https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 *
 * Example 2:
 *
 * Input: root = [1]
 * Output: [[1]]
 *
 * Example 3:
 *
 * Input: root = []
 * Output: []
 *
 *
 * Constraints:
 *
 * The number of nodes in the tree is in the range [0, 2000].
 * -1000 <= Node.val <= 1000
 */

#ifndef LEETCODE_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
#define LEETCODE_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H

#include "common.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **levelOrder_102_1(struct TreeNode *root, int *returnSize,
                       int **returnColumnSizes);

int **levelOrder_102_2(struct TreeNode *root, int *returnSize,
                       int **returnColumnSizes);

#endif //LEETCODE_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
