#include "insertion_sort_list.h"

#include <stdlib.h>

struct ListNode *insertionSortList_147_1(struct ListNode *head) {
    struct ListNode dummy = {};
    struct ListNode *node = head, *next, *pre;
    while (node != NULL) {
        next = node->next;
        pre = &dummy;
        while (pre->next != NULL && node->val > pre->next->val)
            pre = pre->next;
        node->next = pre->next;
        pre->next = node;
        node = next;
    }
    return dummy.next;
}
