#include "populating_next_right_pointers_in_each_node_ii.h"

#include <stddef.h>

struct Node *connect_117_1(struct Node *root) {
    struct Node dummy = {}, *tail, *node = root;
    while (node != NULL) {
        dummy.next = NULL;
        tail = &dummy;
        while (node != NULL) {
            if (node->left != NULL)
                tail = tail->next = node->left;
            if (node->right != NULL)
                tail = tail->next = node->right;
            node = node->next;
        }
        node = dummy.next;
    }
    return root;
}
