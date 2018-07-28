/*
 * Given a binary tree, return the preorder traversal of its nodes' values.
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
 * Output: [1,2,3]
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

#ifndef LEETCODE_BINARY_TREE_PREORDER_TRAVERSAL_H
#define LEETCODE_BINARY_TREE_PREORDER_TRAVERSAL_H

#include "common.h"

int *preorderTraversal_144_1(struct TreeNode *root, int *returnSize);

int *preorderTraversal_144_2(struct TreeNode *root, int *returnSize);

#endif //LEETCODE_BINARY_TREE_PREORDER_TRAVERSAL_H
