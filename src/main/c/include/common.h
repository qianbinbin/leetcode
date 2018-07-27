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

struct Interval {
    int start;
    int end;
};

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

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left, *right, *next;
};

#define NEIGHBORS_MAX_SIZE 100

struct UndirectedGraphNode {
    int label;
    struct UndirectedGraphNode *neighbors[NEIGHBORS_MAX_SIZE];
    int neighborsCount;
};

struct RandomListNode {
    int label;
    struct RandomListNode *next;
    struct RandomListNode *random;
};

#endif //LEETCODE_COMMON_H
