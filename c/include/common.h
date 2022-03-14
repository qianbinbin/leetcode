#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

#include <limits.h>

#define NTNODE INT_MIN

void array_print(int *nums, int numsSize);

struct ListNode {
    int val;
    struct ListNode *next;
};

void list_print(struct ListNode *head);

struct ListNode *list_create(int *nums, int numsSize);

void list_free(struct ListNode *head);

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

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

struct Point {
    int x;
    int y;
};

#endif //LEETCODE_COMMON_H
