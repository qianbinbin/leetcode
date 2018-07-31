#include "reverse_nodes_in_k_group.h"

#include <stdlib.h>

struct ListNode *reverseKGroup_25_1(struct ListNode *head, int k) {
    if (head == NULL || k < 2) return head;

    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *pre = dummy, *tail, *p, *barrier;
    int i;
    while (pre->next != NULL) {
        tail = pre->next;
        barrier = tail;
        for (i = 0; i < k && barrier != NULL; ++i)
            barrier = barrier->next;
        if (i < k)
            break;

        p = tail->next;
        while (p != barrier) {
            tail->next = p->next;
            p->next = pre->next;
            pre->next = p;
            p = tail->next;
        }
        pre = tail;
    }
    head = dummy->next;
    free(dummy);
    return head;
}
