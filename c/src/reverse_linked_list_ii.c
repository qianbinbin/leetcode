#include "reverse_linked_list_ii.h"

struct ListNode *
reverseBetween_92_1(struct ListNode *head, int left, int right) {
    struct ListNode dummy = {0, head}, *tail = &dummy;
    for (int i = 1; i < left; ++i)
        tail = tail->next;

    struct ListNode *first = tail->next, *p;
    for (int i = left; i < right; ++i) {
        p = first->next;
        first->next = p->next;
        p->next = tail->next;
        tail->next = p;
    }
    return dummy.next;
}
