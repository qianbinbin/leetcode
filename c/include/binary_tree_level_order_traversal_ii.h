/*
 * Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).
 *
 *
 *
 * Example 1:
 * https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[15,7],[9,20],[3]]
 *
 * Example 2:
 *
 * Input: root = [1]
 * Output: [[1]]
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

#ifndef LEETCODE_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H
#define LEETCODE_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H

#include "common.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **levelOrderBottom_107_1(struct TreeNode *root, int *returnSize,
                             int **returnColumnSizes);

int **levelOrderBottom_107_2(struct TreeNode *root, int *returnSize,
                             int **returnColumnSizes);

#endif //LEETCODE_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H
