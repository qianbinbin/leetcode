#include <remove_duplicates_from_sorted_list.h>
#include <stdlib.h>

struct ListNode *deleteDuplicates_83(struct ListNode *head) {
    if (head == NULL) return NULL;

    struct ListNode *pre = head, *p = head->next;
    while (p != NULL) {
        if (pre->val == p->val) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
    return head;
}
