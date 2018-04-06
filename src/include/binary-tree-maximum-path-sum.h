#ifndef LEETCODE_BINARY_TREE_MAXIMUM_PATH_SUM_H
#define LEETCODE_BINARY_TREE_MAXIMUM_PATH_SUM_H

#include <common.h>

/**
 * Given a binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
 *
 * For example:
 * Given the below binary tree,
 *
 *        1
 *       / \
 *      2   3
 * Return 6.
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxPathSum_124(struct TreeNode *root);

#endif //LEETCODE_BINARY_TREE_MAXIMUM_PATH_SUM_H
