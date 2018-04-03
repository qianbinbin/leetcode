#ifndef LEETCODE_UNIQUE_BINARY_SEARCH_TREES_II_H
#define LEETCODE_UNIQUE_BINARY_SEARCH_TREES_II_H

#include <common.h>

/**
 * Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 *
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode **generateTrees_95(int n, int *returnSize);

#endif //LEETCODE_UNIQUE_BINARY_SEARCH_TREES_II_H
