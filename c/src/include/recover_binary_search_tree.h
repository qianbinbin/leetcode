/*
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Example 1:
 *
 * Input: [1,3,null,null,2]
 *
 *    1
 *   /
 *  3
 *   \
 *    2
 *
 * Output: [3,1,null,null,2]
 *
 *    3
 *   /
 *  1
 *   \
 *    2
 *
 * Example 2:
 *
 * Input: [3,1,4,null,null,2]
 *
 *   3
 *  / \
 * 1   4
 *    /
 *   2
 *
 * Output: [2,1,4,null,null,3]
 *
 *   2
 *  / \
 * 1   4
 *    /
 *   3
 * Follow up:
 *
 * A solution using O(n) space is pretty straight forward.
 * Could you devise a constant space solution?
 */

#ifndef LEETCODE_RECOVER_BINARY_SEARCH_TREE_H
#define LEETCODE_RECOVER_BINARY_SEARCH_TREE_H

#include "common.h"

void recoverTree_99_1(struct TreeNode *root);

void recoverTree_99_2(struct TreeNode *root);

#endif //LEETCODE_RECOVER_BINARY_SEARCH_TREE_H
