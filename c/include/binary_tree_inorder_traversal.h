/*
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 *
 *
 *
 * Example 1:
 * https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg
 *
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 *
 * Example 2:
 *
 * Input: root = []
 * Output: []
 *
 * Example 3:
 *
 * Input: root = [1]
 * Output: [1]
 *
 *
 * Constraints:
 *
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

#ifndef LEETCODE_BINARY_TREE_INORDER_TRAVERSAL_H
#define LEETCODE_BINARY_TREE_INORDER_TRAVERSAL_H

#include "common.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *inorderTraversal_94_1(struct TreeNode *root, int *returnSize);

int *inorderTraversal_94_2(struct TreeNode *root, int *returnSize);

#endif //LEETCODE_BINARY_TREE_INORDER_TRAVERSAL_H
