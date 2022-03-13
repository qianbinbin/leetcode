#include "copy_list_with_random_pointer.h"

#include <stdlib.h>

struct Node *copyRandomList_138_1(struct Node *head) {
    if (head == NULL) return NULL;

    struct Node *node, *copy;
    for (node = head; node != NULL; node = copy->next) {
        copy = (struct Node *) malloc(sizeof(struct Node));
        copy->val = node->val;
        copy->next = node->next;
        node->next = copy;
    }

    for (node = head; node != NULL; node = copy->next) {
        copy = node->next;
        copy->random = node->random == NULL ? NULL : node->random->next;
    }

    struct Node *ret = head->next;
    for (node = head; node != NULL;) {
        copy = node->next;
        node = node->next = copy->next;
        copy->next = node == NULL ? NULL : node->next;
    }
    return ret;
}
