#include "reverse_linked_list_ii.h"

#include <stdlib.h>

struct ListNode *reverseBetween_92_1(struct ListNode *head, int m, int n) {
    if (head == NULL || m < 1 || n < 1 || m > n) return NULL;
    if (m == n) return head;

    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *tail = dummy;
    for (int i = 1; i < m; ++i) tail = tail->next;

    struct ListNode *first = tail->next;
    struct ListNode *p = first->next;
    for (int i = m; i < n; ++i) {
        first->next = p->next;
        p->next = tail->next;
        tail->next = p;
        p = first->next;
    }
    head = dummy->next;
    free(dummy);
    return head;
}
