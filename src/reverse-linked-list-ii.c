#include <reverse-linked-list-ii.h>
#include <stdlib.h>

struct ListNode *reverseBetween_92(struct ListNode *head, int m, int n) {
    if (head == NULL || m < 1 || n < 1 || m > n) return NULL;
    if (m == n) return head;

    struct ListNode *tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
    tmp->next = head;
    struct ListNode *pre = tmp;
    for (int i = 0; i < m - 1; ++i) pre = pre->next;

    struct ListNode *begin = pre->next;
    struct ListNode *p = begin->next;
    for (int i = m + 1; i <= n; ++i) {
        begin->next = p->next;
        p->next = pre->next;
        pre->next = p;
        p = begin->next;
    }
    if (m == 1) {
        head = pre->next;
    }
    free(tmp);
    return head;
}
