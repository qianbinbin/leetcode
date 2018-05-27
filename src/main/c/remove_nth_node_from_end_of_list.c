#include "remove_nth_node_from_end_of_list.h"

#include <stdlib.h>

struct ListNode *removeNthFromEnd_19_1(struct ListNode *head, int n) {
    if (head == NULL || n < 1) return head;

    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *fast = dummy, *slow = dummy;
    while (n >= 0 && fast != NULL) {
        fast = fast->next;
        --n;
    }
    if (n >= 0) {
        free(dummy);
        return head;
    }
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    struct ListNode *rm = slow->next;
    slow->next = rm->next;
    free(rm);
    head = dummy->next;
    free(dummy);
    return head;
}
