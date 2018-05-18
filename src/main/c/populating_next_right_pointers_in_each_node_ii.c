#include <populating_next_right_pointers_in_each_node_ii.h>
#include <stddef.h>

void connect_117(struct TreeLinkNode *root) {
    if (root == NULL) return;

    struct TreeLinkNode *cur = root, *p = NULL, *leading = NULL;
    while (cur != NULL) {
        while (cur != NULL) {
            if (cur->left != NULL) {
                if (leading == NULL) leading = cur->left;
                if (p != NULL) {
                    p->next = cur->left;
                }
                p = cur->left;
            }
            if (cur->right != NULL) {
                if (leading == NULL) leading = cur->right;
                if (p != NULL) {
                    p->next = cur->right;
                }
                p = cur->right;
            }
            cur = cur->next;
        }
        cur = leading;
        leading = NULL;
        p = NULL;
    }
}
