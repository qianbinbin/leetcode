#include "remove_nth_node_from_end_of_list.h"

#include <stdlib.h>

struct ListNode *removeNthFromEnd_19_1(struct ListNode *head, int n) {
    struct ListNode dummy = {0, head};
    struct ListNode *fast = &dummy, *slow = &dummy;
    for (; n >= 0; --n)
        fast = fast->next;
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    struct ListNode *rm = slow->next;
    slow->next = rm->next;
    free(rm);
    return dummy.next;
}
