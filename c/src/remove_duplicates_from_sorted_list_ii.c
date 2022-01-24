#include "remove_duplicates_from_sorted_list_ii.h"

#include <stdlib.h>

struct ListNode *deleteDuplicates_82_1(struct ListNode *head) {
    struct ListNode dummy = {0, head};
    struct ListNode *tail = &dummy, *p = head;
    int skip;
    while (p != NULL) {
        if (p->next != NULL && p->next->val == p->val) {
            skip = p->val;
            while (p != NULL && p->val == skip) {
                tail->next = p->next;
                free(p);
                p = tail->next;
            }
        } else {
            tail = p;
            p = p->next;
        }
    }
    return dummy.next;
}
