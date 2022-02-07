/*
 * Given the root of a binary tree, return its maximum depth.
 *
 * A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 *
 *
 *
 * Example 1:
 * https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 3
 *
 * Example 2:
 *
 * Input: root = [1,null,2]
 * Output: 2
 *
 *
 * Constraints:
 *
 * The number of nodes in the tree is in the range [0, 104].
 * -100 <= Node.val <= 100
 */

#ifndef LEETCODE_MAXIMUM_DEPTH_OF_BINARY_TREE_H
#define LEETCODE_MAXIMUM_DEPTH_OF_BINARY_TREE_H

#include "common.h"

int maxDepth_104_1(struct TreeNode *root);

#endif //LEETCODE_MAXIMUM_DEPTH_OF_BINARY_TREE_H
