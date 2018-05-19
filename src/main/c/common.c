#include "common.h"

#include <stdio.h>
#include <stdlib.h>

void array_print(int *nums, int numsSize) {
    if (nums == NULL) return;
    printf("[");
    if (numsSize > 0) {
        printf("%d", nums[0]);
        for (int i = 1; i < numsSize; ++i) {
            printf(",%d", nums[i]);
        }
    }
    printf("]\n");
}

void list_print(struct ListNode *head) {
    if (head == NULL) return;
    printf("%d", head->val);
    while (head->next != NULL) {
        printf("->%d", head->next->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode *list_create(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return NULL;

    struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));
    head->val = nums[0];
    struct ListNode *tail = head;
    for (int i = 1; i < numsSize; ++i) {
        struct ListNode *tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
        tmp->val = nums[i];
        tail->next = tmp;
        tail = tail->next;
    }
    tail->next = NULL;
    return head;
}

void list_free(struct ListNode *head) {
    struct ListNode *pre;
    while (head != NULL) {
        pre = head;
        head = pre->next;
        free(pre);
    }
}

static struct TreeNode *tree_node_create(int val) {
    if (val == INT_NULL_TREE_NODE) return NULL;

    struct TreeNode *node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static struct TreeNode **tree_node_array(int *nums, int numsSize) {
    struct TreeNode **array = (struct TreeNode **) malloc(numsSize * sizeof(struct TreeNode *));
    for (int i = 0; i < numsSize; ++i) {
        array[i] = tree_node_create(nums[i]);
    }
    return array;
}

static struct TreeNode *tree_create_from_array(int *nums, int numsSize) {
    struct TreeNode **nodes = tree_node_array(nums, numsSize);
    for (int i = 0; i < numsSize; ++i) {
        if (nodes[i] != NULL) {
            nodes[i]->left = (2 * i + 1 < numsSize) ? nodes[2 * i + 1] : NULL;
            nodes[i]->right = (2 * i + 2 < numsSize) ? nodes[2 * i + 2] : NULL;
        }
    }
    struct TreeNode *root = nodes[0];
    free(nodes);
    return root;
}

struct TreeNode *tree_create(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return NULL;
    return tree_create_from_array(nums, numsSize);
}

static void tree_preorder(struct TreeNode *root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    tree_preorder(root->left);
    tree_preorder(root->right);
}

void tree_preorder_print(struct TreeNode *root) {
    if (root == NULL) return;
    tree_preorder(root);
    printf("\n");
}

static void tree_inorder(struct TreeNode *root) {
    if (root == NULL) return;
    tree_inorder(root->left);
    printf("%d ", root->val);
    tree_inorder(root->right);
}

void tree_inorder_print(struct TreeNode *root) {
    if (root == NULL) return;
    tree_inorder(root);
    printf("\n");
}

static void tree_postorder(struct TreeNode *root) {
    if (root == NULL) return;
    tree_postorder(root->left);
    tree_postorder(root->right);
    printf("%d ", root->val);
}

void tree_postorder_print(struct TreeNode *root) {
    if (root == NULL) return;
    tree_postorder(root);
    printf("\n");
}

void tree_free(struct TreeNode *root) {
    if (root == NULL) return;

    tree_free(root->left);
    tree_free(root->right);
    free(root);
}
