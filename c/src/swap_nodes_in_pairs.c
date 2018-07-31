#include "swap_nodes_in_pairs.h"

#include <stdlib.h>

struct ListNode *swapPairs_24_1(struct ListNode *head) {
    if (head == NULL) return NULL;

    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *pre = dummy, *p = head;
    while (p != NULL && p->next != NULL) {
        pre->next = p->next;
        p->next = pre->next->next;
        pre->next->next = p;
        pre = p;
        p = p->next;
    }
    head = dummy->next;
    free(dummy);
    return head;
}
