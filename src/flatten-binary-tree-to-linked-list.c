#include <flatten-binary-tree-to-linked-list.h>
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
