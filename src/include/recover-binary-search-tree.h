#ifndef LEETCODE_RECOVER_BINARY_SEARCH_TREE_H
#define LEETCODE_RECOVER_BINARY_SEARCH_TREE_H

#include <common.h>

/**
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void recoverTree_99_1(struct TreeNode *root);

#endif //LEETCODE_RECOVER_BINARY_SEARCH_TREE_H
