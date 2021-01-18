/*
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 * Example 1:
 *
 * Input:
 *     2
 *    / \
 *   1   3
 * Output: true
 *
 * Example 2:
 *
 *     5
 *    / \
 *   1   4
 *      / \
 *     3   6
 * Output: false
 * Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
 *              is 5 but its right child's value is 4.
 */

#ifndef LEETCODE_VALIDATE_BINARY_SEARCH_TREE_H
#define LEETCODE_VALIDATE_BINARY_SEARCH_TREE_H

#include "common.h"

#include <stdbool.h>

bool isValidBST_98_1(struct TreeNode *root);

bool isValidBST_98_2(struct TreeNode *root);

#endif //LEETCODE_VALIDATE_BINARY_SEARCH_TREE_H
