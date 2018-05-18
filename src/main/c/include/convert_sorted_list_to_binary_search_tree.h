#ifndef LEETCODE_CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE_H
#define LEETCODE_CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE_H

#include <common.h>

/**
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 *
 *
 * Example:
 *
 * Given the sorted linked list: [-10,-3,0,5,9],
 *
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
 *
 *       0
 *      / \
 *    -3   9
 *    /   /
 *  -10  5
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *sortedListToBST_109(struct ListNode *head);

#endif //LEETCODE_CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE_H
