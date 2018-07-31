#include "populating_next_right_pointers_in_each_node_ii.h"

#include <stdlib.h>

void connect_117_1(struct TreeLinkNode *root) {
    if (root == NULL) return;

    struct TreeLinkNode *dummy = (struct TreeLinkNode *) malloc(sizeof(struct TreeLinkNode));
    dummy->next = NULL;
    struct TreeLinkNode *tail = dummy;
    while (root != NULL) {
        if (root->left != NULL) {
            tail->next = root->left;
            tail = tail->next;
        }
        if (root->right != NULL) {
            tail->next = root->right;
            tail = tail->next;
        }
        if (root->next != NULL) {
            root = root->next;
        } else {
            root = dummy->next;
            dummy->next = NULL;
            tail = dummy;
        }
    }
}
