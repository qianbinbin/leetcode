#include <reverse-nodes-in-k-group.h>
#include <stdlib.h>

struct ListNode *reverseKGroup_25(struct ListNode *head, int k) {
    if (head == NULL || k < 2) return head;

    struct ListNode *list = (struct ListNode *) malloc(sizeof(struct ListNode));
    list->next = head;
    struct ListNode *pre = list, *p, *tail, *barrier;
    int count;
    while (pre->next != NULL) {
        tail = pre->next;
        barrier = tail;
        for (count = 0; count < k && barrier != NULL; ++count) {
            barrier = barrier->next;
        }
        if (barrier == NULL && count < k) break;

        p = tail->next;
        while (p != barrier) {
            tail->next = p->next;
            p->next = pre->next;
            pre->next = p;
            p = tail->next;
        }
        pre = tail;
    }
    head = list->next;
    free(list);
    return head;
}
