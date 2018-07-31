#include "insertion_sort_list.h"

#include <stdlib.h>

struct ListNode *insertionSortList_147_1(struct ListNode *head) {
    if (head == NULL) return NULL;

    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *p = head->next, *pre = dummy, *unsorted;
    head->next = NULL;

    while (p != NULL) {
        while (pre->next != NULL && p->val > pre->next->val)
            pre = pre->next;
        unsorted = p->next;
        p->next = pre->next;
        pre->next = p;
        p = unsorted;
        pre = dummy;
    }

    head = dummy->next;
    free(dummy);
    return head;
}
