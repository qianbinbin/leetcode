#ifndef LEETCODE_MINIMUM_DEPTH_OF_BINARY_TREE_H
#define LEETCODE_MINIMUM_DEPTH_OF_BINARY_TREE_H

#include <common.h>

/**
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth_111(struct TreeNode *root);

#endif //LEETCODE_MINIMUM_DEPTH_OF_BINARY_TREE_H
