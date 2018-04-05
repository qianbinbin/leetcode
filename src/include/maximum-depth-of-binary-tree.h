#ifndef LEETCODE_MAXIMUM_DEPTH_OF_BINARY_TREE_H
#define LEETCODE_MAXIMUM_DEPTH_OF_BINARY_TREE_H

#include <common.h>

/**
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its depth = 3.
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth_104(struct TreeNode *root);

#endif //LEETCODE_MAXIMUM_DEPTH_OF_BINARY_TREE_H
