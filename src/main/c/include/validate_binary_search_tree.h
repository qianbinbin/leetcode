#ifndef LEETCODE_VALIDATE_BINARY_SEARCH_TREE_H
#define LEETCODE_VALIDATE_BINARY_SEARCH_TREE_H

#include <common.h>
#include <stdbool.h>

/**
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 * Example 1:
 *     2
 *    / \
 *   1   3
 * Binary tree [2,1,3], return true.
 *
 * Example 2:
 *     1
 *    / \
 *   2   3
 * Binary tree [1,2,3], return false.
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST_98(struct TreeNode *root);

#endif //LEETCODE_VALIDATE_BINARY_SEARCH_TREE_H
