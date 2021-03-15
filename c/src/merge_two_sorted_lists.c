#include "merge_two_sorted_lists.h"

#include <stdlib.h>

struct ListNode *mergeTwoLists_21_1(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode dummy = {0, NULL}, *tail = &dummy;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
    }
    tail->next = l1 != NULL ? l1 : l2;
    return dummy.next;
}
