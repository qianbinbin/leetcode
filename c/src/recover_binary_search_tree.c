#include "recover_binary_search_tree.h"

#include <stdlib.h>

static void append_node(struct TreeNode ***nodes, int *size, int *capacity,
                        struct TreeNode *node) {
    if (*size >= *capacity) {
        *capacity *= 2;
        *nodes = realloc(*nodes, (*capacity) * sizeof(struct TreeNode *));
    }
    (*nodes)[(*size)++] = node;
}

static void
traverse_inorder(struct TreeNode *root, struct TreeNode ***nodes, int *size,
                 int *capacity) {
    if (root == NULL) return;

    traverse_inorder(root->left, nodes, size, capacity);
    append_node(nodes, size, capacity, root);
    traverse_inorder(root->right, nodes, size, capacity);
}

void recoverTree_99_1(struct TreeNode *root) {
    int size = 0;
    int capacity = 16;
    struct TreeNode **nodes = (struct TreeNode **) malloc(
            capacity * sizeof(struct TreeNode *));
    traverse_inorder(root, &nodes, &size, &capacity);
    int i = 0, j = size - 1;
    while (i < j && nodes[i]->val < nodes[i + 1]->val) ++i;
    while (j > i && nodes[j]->val > nodes[j - 1]->val) --j;
    int tmp = nodes[i]->val;
    nodes[i]->val = nodes[j]->val;
    nodes[j]->val = tmp;
    free(nodes);
}

static void in_order(struct TreeNode *root, struct TreeNode **pre,
                     struct TreeNode **invalid1, struct TreeNode **invalid2) {
    if (root == NULL) return;
    in_order(root->left, pre, invalid1, invalid2);
    if (*pre != NULL && (*pre)->val > root->val) {
        if (*invalid1 == NULL)
            *invalid1 = *pre;
        *invalid2 = root;
    }
    *pre = root;
    in_order(root->right, pre, invalid1, invalid2);
}

void recoverTree_99_2(struct TreeNode *root) {
    struct TreeNode *pre = NULL, *invalid1 = NULL, *invalid2 = NULL;
    in_order(root, &pre, &invalid1, &invalid2);
    int tmp = invalid1->val;
    invalid1->val = invalid2->val;
    invalid2->val = tmp;
}
