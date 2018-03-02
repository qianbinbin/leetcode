#include <reorder-list.h>
#include <stdlib.h>

void reorderList_143(struct ListNode *head) {
    if (head == NULL) return;

    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = slow;
    struct ListNode *p = slow->next;
    while (p != NULL) {
        slow->next = p->next;
        p->next = dummy->next;
        dummy->next = p;
        p = slow->next;
    }
    struct ListNode *p1 = head;
    p = dummy->next;
    while (p1->next != slow) {
        dummy->next = p->next;
        p->next = p1->next;
        p1->next = p;
        p1 = p->next;
        p = dummy->next;
    }
    p1->next = dummy->next;
    free(dummy);
}
