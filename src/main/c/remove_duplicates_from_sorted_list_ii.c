#include "remove_duplicates_from_sorted_list_ii.h"

#include <stdlib.h>

struct ListNode *deleteDuplicates_82_1(struct ListNode *head) {
    if (head == NULL) return NULL;

    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *tail = dummy, *p = head, *rm;
    while (p != NULL) {
        if (p->next == NULL || p->next->val != p->val) {
            tail->next = p;
            tail = p;
            p = p->next;
        } else {
            int skip = p->val;
            while (p != NULL && p->val == skip) {
                rm = p;
                p = p->next;
                free(rm);
            }
        }
    }
    tail->next = NULL;
    head = dummy->next;
    free(dummy);
    return head;
}
