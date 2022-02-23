#include "populating_next_right_pointers_in_each_node.h"

#include <stddef.h>

struct Node *connect_116_1(struct Node *root) {
    if (root == NULL)
        return NULL;
    struct Node dummy, *tail, *node = root;
    while (node->left != NULL) {
        tail = &dummy;
        while (node != NULL) {
            tail = tail->next = node->left;
            tail = tail->next = node->right;
            node = node->next;
        }
        node = dummy.next;
    }
    return root;
}

struct Node *connect_116_2(struct Node *root) {
    if (root == NULL || root->left == NULL)
        return root;
    root->left->next = root->right;
    if (root->next != NULL)
        root->right->next = root->next->left;
    connect_116_1(root->left);
    connect_116_1(root->right);
    return root;
}
