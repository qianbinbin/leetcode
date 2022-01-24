#include "remove_duplicates_from_sorted_list.h"

#include <stdlib.h>

struct ListNode *deleteDuplicates_83_1(struct ListNode *head) {
    if (head == NULL)
        return NULL;

    struct ListNode *tail = head, *p = head->next;
    while (p != NULL) {
        if (p->val != tail->val) {
            tail->next = p;
            tail = p;
        } else {
            tail->next = p->next;
            free(p);
        }
        p = tail->next;
    }
    return head;
}
