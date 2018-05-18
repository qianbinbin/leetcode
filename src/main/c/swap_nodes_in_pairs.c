#include <swap_nodes_in_pairs.h>
#include <stdlib.h>

struct ListNode *swapPairs_24(struct ListNode *head) {
    if (head == NULL) return NULL;

    struct ListNode *list = (struct ListNode *) malloc(sizeof(struct ListNode));
    list->next = head;
    struct ListNode *pre = list, *p = head;
    while (p != NULL && p->next != NULL) {
        pre->next = p->next;
        p->next = pre->next->next;
        pre->next->next = p;
        pre = p;
        p = p->next;
    }
    head = list->next;
    free(list);
    return head;
}
