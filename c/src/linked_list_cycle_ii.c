#include "linked_list_cycle_ii.h"

#include <stddef.h>

struct ListNode *detectCycle_142_1(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            struct ListNode *node = head;
            while (slow != node) {
                slow = slow->next;
                node = node->next;
            }
            return slow;
        }
    }
    return NULL;
}
