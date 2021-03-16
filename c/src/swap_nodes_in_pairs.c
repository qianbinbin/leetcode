#include "swap_nodes_in_pairs.h"

#include <stdlib.h>

struct ListNode *swapPairs_24_1(struct ListNode *head) {
    struct ListNode dummy = {0, head};
    struct ListNode *tail = &dummy, *p1 = head, *p2;
    while (p1 != NULL && (p2 = p1->next) != NULL) {
        p1->next = p2->next;
        p2->next = p1;
        tail->next = p2;
        tail = p1;
        p1 = p1->next;
    }
    return dummy.next;
}
