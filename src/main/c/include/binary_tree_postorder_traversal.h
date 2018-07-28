/*
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
 * Output: [3,2,1]
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

#ifndef LEETCODE_BINARY_TREE_POSTORDER_TRAVERSAL_H
#define LEETCODE_BINARY_TREE_POSTORDER_TRAVERSAL_H

#include "common.h"

int *postorderTraversal_145_1(struct TreeNode *root, int *returnSize);

int *postorderTraversal_145_2(struct TreeNode *root, int *returnSize);

int *postorderTraversal_145_3(struct TreeNode *root, int *returnSize);

#endif //LEETCODE_BINARY_TREE_POSTORDER_TRAVERSAL_H
