#include <linked_list_cycle_ii.h>
#include <stddef.h>

struct ListNode *detectCycle_142(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            struct ListNode *slow1 = head;
            while (slow != slow1) {
                slow = slow->next;
                slow1 = slow1->next;
            }
            return slow;
        }
    }
    return NULL;
}
