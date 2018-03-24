#ifndef LEETCODE_BINARY_TREE_POSTORDER_TRAVERSAL_H
#define LEETCODE_BINARY_TREE_POSTORDER_TRAVERSAL_H

#include <common.h>

/**
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree [1,null,2,3],
 *
 *    1
 *     \
 *      2
 *     /
 *    3
 *
 *
 * return [3,2,1].
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
int *postorderTraversal_145_1(struct TreeNode *root, int *returnSize);

#endif //LEETCODE_BINARY_TREE_POSTORDER_TRAVERSAL_H
