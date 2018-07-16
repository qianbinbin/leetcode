/*
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * return its bottom-up level order traversal as:
 *
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
 */

#ifndef LEETCODE_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H
#define LEETCODE_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H

#include "common.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **levelOrderBottom_107_1(struct TreeNode *root, int **columnSizes, int *returnSize);

int **levelOrderBottom_107_2(struct TreeNode *root, int **columnSizes, int *returnSize);

#endif //LEETCODE_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H
