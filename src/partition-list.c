#include <partition-list.h>
#include <stdlib.h>

struct ListNode *partition_86(struct ListNode *head, int x) {
    if (head == NULL) return NULL;

    struct ListNode *list = (struct ListNode *) malloc(sizeof(struct ListNode));
    list->next = head;
    struct ListNode *last = list;
    while (last->next != NULL && last->next->val < x) last = last->next;
    struct ListNode *pre = last, *p = last->next;
    while (p != NULL) {
        if (p->val < x) {
            pre->next = p->next;
            p->next = last->next;
            last->next = p;
            last = p;
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
    head = list->next;
    free(list);
    return head;
}
