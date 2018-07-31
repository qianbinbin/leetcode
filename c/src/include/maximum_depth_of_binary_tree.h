/*
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given binary tree [3,9,20,null,null,15,7],
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * return its depth = 3.
 */

#ifndef LEETCODE_MAXIMUM_DEPTH_OF_BINARY_TREE_H
#define LEETCODE_MAXIMUM_DEPTH_OF_BINARY_TREE_H

#include "common.h"

int maxDepth_104_1(struct TreeNode *root);

#endif //LEETCODE_MAXIMUM_DEPTH_OF_BINARY_TREE_H
