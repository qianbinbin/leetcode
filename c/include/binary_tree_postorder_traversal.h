/*
 * Given the root of a binary tree, return the postorder traversal of its nodes' values.
 *
 *
 *
 * Example 1:
 * https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg
 *
 * Input: root = [1,null,2,3]
 * Output: [3,2,1]
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
 * The number of the nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
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
