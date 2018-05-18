#include <recover_binary_search_tree.h>
#include <stdlib.h>

static void append_node(struct TreeNode ***nodes, int *size, int *capacity, struct TreeNode *node) {
    if (*size >= *capacity) {
        *capacity *= 2;
        *nodes = realloc(*nodes, (*capacity) * sizeof(struct TreeNode *));
    }
    (*nodes)[(*size)++] = node;
}

static void traverse_inorder(struct TreeNode *root, struct TreeNode ***nodes, int *size, int *capacity) {
    if (root == NULL) return;

    traverse_inorder(root->left, nodes, size, capacity);
    append_node(nodes, size, capacity, root);
    traverse_inorder(root->right, nodes, size, capacity);
}

void recoverTree_99_1(struct TreeNode *root) {
    if (root == NULL) return;

    int size = 0;
    int capacity = 64;
    struct TreeNode **nodes = (struct TreeNode **) malloc(capacity * sizeof(struct TreeNode *));
    traverse_inorder(root, &nodes, &size, &capacity);
    struct TreeNode *p1 = NULL, *p2 = NULL;
    for (int i = 0; i < size - 1; ++i) {
        if (nodes[i]->val > nodes[i + 1]->val) {
            p1 = nodes[i];
            break;
        }
    }
    for (int i = size - 1; i > 0; --i) {
        if (nodes[i]->val < nodes[i - 1]->val) {
            p2 = nodes[i];
            break;
        }
    }
    if (p1 != NULL && p2 != NULL) {
        int tmp = p1->val;
        p1->val = p2->val;
        p2->val = tmp;
    }
    free(nodes);
}
