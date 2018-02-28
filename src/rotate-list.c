#include <rotate-list.h>
#include <stddef.h>

struct ListNode *rotateRight_61(struct ListNode *head, int k) {
    if (head == NULL || k < 1) return head;

    int size = 0;
    for (struct ListNode *p = head; p != NULL; p = p->next) ++size;
    k %= size;

    struct ListNode *p1 = head, *p2 = head;
    while (k-- > 0) p2 = p2->next;
    while (p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }
    p2->next = head;
    head = p1->next;
    p1->next = NULL;
    return head;
}
