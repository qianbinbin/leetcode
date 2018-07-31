/*
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 *
 * Input: [1,null,2,3]
 *    1
 *     \
 *      2
 *     /
 *    3
 *
 * Output: [1,3,2]
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

#ifndef LEETCODE_BINARY_TREE_INORDER_TRAVERSAL_H
#define LEETCODE_BINARY_TREE_INORDER_TRAVERSAL_H

#include "common.h"

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *inorderTraversal_94_1(struct TreeNode *root, int *returnSize);

int *inorderTraversal_94_2(struct TreeNode *root, int *returnSize);

#endif //LEETCODE_BINARY_TREE_INORDER_TRAVERSAL_H
