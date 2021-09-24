#include "rotate_list.h"

#include <stddef.h>

struct ListNode *rotateRight_61_1(struct ListNode *head, int k) {
    int size = 0;
    for (struct ListNode *p = head; p != NULL; p = p->next) ++size;
    k %= size;

    struct ListNode *slow = head, *fast = head;
    while (k-- > 0) fast = fast->next;
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = head;
    head = slow->next;
    slow->next = NULL;
    return head;
}
