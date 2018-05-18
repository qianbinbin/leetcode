#include <symmetric_tree.h>
#include <stdlib.h>

static bool is_symmetric(struct TreeNode *p, struct TreeNode *q) {
    if (p == q) return true;
    if (p == NULL || q == NULL) return p == q;
    return p->val == q->val && is_symmetric(p->left, q->right) && is_symmetric(p->right, q->left);
}

bool isSymmetric_101_1(struct TreeNode *root) {
    if (root == NULL) return true;
    return is_symmetric(root->left, root->right);
}

bool isSymmetric_101_2(struct TreeNode *root) {
    if (root == NULL) return true;

    int capacity = 64;
    struct TreeNode **stack = (struct TreeNode **) malloc(capacity * sizeof(struct TreeNode *));
    int top = -1;
    stack[++top] = root->left;
    stack[++top] = root->right;

    bool is_sym = true;
    struct TreeNode *p1 = NULL, *p2 = NULL;
    while (top > -1) {
        p1 = stack[top--];
        p2 = stack[top--];
        if (p1 == NULL && p2 == NULL) continue;
        if (p1 == NULL || p2 == NULL) {
            is_sym = false;
            break;
        }
        if (p1->val != p2->val) {
            is_sym = false;
            break;
        }
        if (top + 1 + 4 >= capacity) {
            capacity *= 2;
            stack = realloc(stack, capacity * sizeof(struct TreeNode *));
        }
        stack[++top] = p1->left;
        stack[++top] = p2->right;
        stack[++top] = p1->right;
        stack[++top] = p2->left;
    }
    free(stack);
    return is_sym;
}
