#include "partition_list.h"

#include <stdlib.h>

struct ListNode *partition_86_1(struct ListNode *head, int x) {
    if (head == NULL) return NULL;

    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *tail = dummy;
    while (tail->next != NULL && tail->next->val < x) tail = tail->next;
    struct ListNode *pre = tail, *p = tail->next;
    while (p != NULL) {
        if (p->val < x) {
            pre->next = p->next;
            p->next = tail->next;
            tail->next = p;
            tail = p;
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
    head = dummy->next;
    free(dummy);
    return head;
}
