#ifndef LEETCODE_FLATTEN_BINARY_TREE_TO_LINKED_LIST_H
#define LEETCODE_FLATTEN_BINARY_TREE_TO_LINKED_LIST_H

#include <common.h>

/**
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example,
 * Given
 *
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 *
 * The flattened tree should look like:
 *
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 *
 * Hints:
 * If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Recurse
 */
void flatten_114_1(struct TreeNode *root);

#endif //LEETCODE_FLATTEN_BINARY_TREE_TO_LINKED_LIST_H
