/*
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example, given the following tree:
 *
 *     1
 *    / \
 *   2   5
 *  / \   \
 * 3   4   6
 *
 * The flattened tree should look like:
 *
 * 1
 *  \
 *   2
 *    \
 *     3
 *      \
 *       4
 *        \
 *         5
 *          \
 *           6
 */

#ifndef LEETCODE_FLATTEN_BINARY_TREE_TO_LINKED_LIST_H
#define LEETCODE_FLATTEN_BINARY_TREE_TO_LINKED_LIST_H

#include "common.h"

void flatten_114_1(struct TreeNode *root);

void flatten_114_2(struct TreeNode *root);

#endif //LEETCODE_FLATTEN_BINARY_TREE_TO_LINKED_LIST_H
