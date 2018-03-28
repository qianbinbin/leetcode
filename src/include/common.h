#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

void array_print(int *nums, int numsSize);

struct ListNode {
    int val;
    struct ListNode *next;
};

void list_print(struct ListNode *head);

struct ListNode *list_from_array(int *nums, int numsSize);

void list_free(struct ListNode *head);

#include <limits.h>

#define INT_NULL_TREE_NODE INT_MIN

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *tree_create_node(int val);

/**
 * Create a binary tree from an array
 *
 * For example:
 * Given an array [1,2,3,null,null,4,null],
 * Return a binary:
 *    1
 *   / \
 *  2   3
 *     /
 *    4
 */
struct TreeNode *tree_create(int *nums, int numsSize);

void tree_preorder_print(struct TreeNode *root);

void tree_inorder_print(struct TreeNode *root);

void tree_postorder_print(struct TreeNode *root);

void tree_free(struct TreeNode *root);

#endif //LEETCODE_COMMON_H
