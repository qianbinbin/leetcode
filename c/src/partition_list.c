#include "partition_list.h"

#include <stdlib.h>

struct ListNode *partition_86_1(struct ListNode *head, int x) {
    struct ListNode dummy1 = {}, *tail1 = &dummy1, dummy2 = {}, *tail2 = &dummy2;
    for (struct ListNode *p = head; p != NULL; p = p->next) {
        if (p->val < x)
            tail1 = (tail1->next = p);
        else
            tail2 = (tail2->next = p);
    }
    tail1->next = dummy2.next;
    tail2->next = NULL;
    return dummy1.next;
}
