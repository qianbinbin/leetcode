#include <remove-nth-node-from-end-of-list.h>
#include <stdlib.h>

struct ListNode *removeNthFromEnd_19(struct ListNode *head, int n) {
    if (head == NULL || n < 1) return head;

    struct ListNode *list = (struct ListNode *) malloc(sizeof(struct ListNode));
    list->next = head;
    struct ListNode *p1 = list, *p2 = head;
    while (n-- > 0) {
        if (p2 == NULL) {
            free(list);
            return NULL;
        }
        p2 = p2->next;
    }
    while (p2 != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }
    struct ListNode *rm = p1->next;
    p1->next = rm->next;
    free(rm);
    head = list->next;
    free(list);
    return head;
}
