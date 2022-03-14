#include "reorder_list.h"

#include <stdlib.h>

void reorderList_143_1(struct ListNode *head) {
    if (head == NULL) return;

    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode dummy = {0, slow};
    struct ListNode *p;
    while ((p = slow->next) != NULL) {
        slow->next = p->next;
        p->next = dummy.next;
        dummy.next = p;
    }
    struct ListNode *p1 = head, *p2 = dummy.next, *tail = &dummy;
    while (p1 != slow) {
        tail = tail->next = p1;
        p1 = p1->next;
        tail = tail->next = p2;
        p2 = p2->next;
    }
}
