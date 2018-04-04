#ifndef LEETCODE_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H
#define LEETCODE_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H

#include <common.h>

/**
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 *
 *
 * Example:
 *
 * Given the sorted array: [-10,-3,0,5,9],
 *
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
 *
 *       0
 *      / \
 *    -3   9
 *    /   /
 *  -10  5
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *sortedArrayToBST_108(int *nums, int numsSize);

#endif //LEETCODE_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H
