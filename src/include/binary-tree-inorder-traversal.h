#ifndef LEETCODE_BINARY_TREE_INORDER_TRAVERSAL_H
#define LEETCODE_BINARY_TREE_INORDER_TRAVERSAL_H

#include <common.h>

/**
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree [1,null,2,3],
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,3,2].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 *
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Recurse
 */
int *inorderTraversal_94_1(struct TreeNode *root, int *returnSize);

#endif //LEETCODE_BINARY_TREE_INORDER_TRAVERSAL_H
