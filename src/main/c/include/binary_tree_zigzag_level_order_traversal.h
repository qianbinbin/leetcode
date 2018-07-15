/*
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
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
 * return its zigzag level order traversal as:
 *
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 */

#ifndef LEETCODE_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
#define LEETCODE_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H

#include "common.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **zigzagLevelOrder_103_1(struct TreeNode *root, int **columnSizes, int *returnSize);

int **zigzagLevelOrder_103_2(struct TreeNode *root, int **columnSizes, int *returnSize);

#endif //LEETCODE_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
