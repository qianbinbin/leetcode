#include "reverse_nodes_in_k_group.h"

#include <stdlib.h>

struct ListNode *reverseKGroup_25_1(struct ListNode *head, int k) {
    struct ListNode dummy = {0, head};
    struct ListNode *tail = &dummy, *first, *p, *end;
    int i;
    while ((first = tail->next) != NULL) {
        end = first;
        for (i = 0; i < k && end != NULL; ++i)
            end = end->next;
        if (i < k)
            break;

        p = first->next;
        while (p != end) {
            first->next = p->next;
            p->next = tail->next;
            tail->next = p;
            p = first->next;
        }
        tail = first;
    }
    return dummy.next;
}
