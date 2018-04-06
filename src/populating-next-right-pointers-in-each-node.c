#include <populating-next-right-pointers-in-each-node.h>
#include <stddef.h>

void connect_116_1(struct TreeLinkNode *root) {
    if (root == NULL) return;
    if (root->left != NULL) {
        root->left->next = root->right;
        if (root->next != NULL)
            root->right->next = root->next->left;
    }
    connect_116_1(root->left);
    connect_116_1(root->right);
}
