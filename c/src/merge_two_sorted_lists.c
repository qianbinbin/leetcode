#include "merge_two_sorted_lists.h"

#include <stdlib.h>

struct ListNode *mergeTwoLists_21_1(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode *tail = dummy;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1 != NULL)
        tail->next = l1;
    else if (l2 != NULL)
        tail->next = l2;
    struct ListNode *ret = dummy->next;
    free(dummy);
    return ret;
}
