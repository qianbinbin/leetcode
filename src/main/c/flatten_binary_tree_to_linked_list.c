#include <flatten_binary_tree_to_linked_list.h>
#include <stdlib.h>

void flatten_114_1(struct TreeNode *root) {
    if (root == NULL) return;
    flatten_114_1(root->left);
    flatten_114_1(root->right);
    if (root->left != NULL) {
        struct TreeNode *l_last = root->left;
        while (l_last->right != NULL) l_last = l_last->right;
        l_last->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
}

void flatten_114_2(struct TreeNode *root) {
    if (root == NULL) return;

    int capacity = 64;
    struct TreeNode **stack = (struct TreeNode **) malloc(capacity * sizeof(struct TreeNode *));
    int top = -1;
    stack[++top] = root;
    struct TreeNode *p;
    while (top >= 0) {
        p = stack[top--];
        if (p->right != NULL) {
            if (top + 1 >= capacity) {
                capacity *= 2;
                stack = (struct TreeNode **) realloc(stack, capacity * sizeof(struct TreeNode *));
            }
            stack[++top] = p->right;
        }
        if (p->left != NULL) {
            if (top + 1 >= capacity) {
                capacity *= 2;
                stack = (struct TreeNode **) realloc(stack, capacity * sizeof(struct TreeNode *));
            }
            stack[++top] = p->left;
        }
        p->left = NULL;
        if (top >= 0) {
            p->right = stack[top];
        }
    }
}
