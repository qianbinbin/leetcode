/*
 * Given a non-empty binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
 *
 * Example 1:
 *
 * Input: [1,2,3]
 *
 *        1
 *       / \
 *      2   3
 *
 * Output: 6
 *
 * Example 2:
 *
 * Input: [-10,9,20,null,null,15,7]
 *
 *    -10
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * Output: 42
 */

#ifndef LEETCODE_BINARY_TREE_MAXIMUM_PATH_SUM_H
#define LEETCODE_BINARY_TREE_MAXIMUM_PATH_SUM_H

#include "common.h"

int maxPathSum_124_1(struct TreeNode *root);

#endif //LEETCODE_BINARY_TREE_MAXIMUM_PATH_SUM_H
