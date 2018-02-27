#include <add-two-numbers.h>
#include <stdlib.h>

struct ListNode *addTwoNumbers_2(struct ListNode *l1, struct ListNode *l2) {
    if (l1 == NULL || l2 == NULL) return NULL;

    struct ListNode *p1 = l1, *p2 = l2;
    struct ListNode *l = (struct ListNode *) malloc(sizeof(struct ListNode));
    l->next = NULL;
    struct ListNode *p, *pre = l;
    int carry = 0, sum = 0;
    while (p1 != NULL && p2 != NULL) {
        p = (struct ListNode *) malloc(sizeof(struct ListNode));
        p->next = NULL;
        sum = p1->val + p2->val + carry;
        p->val = sum % 10;
        carry = sum / 10;
        pre->next = p;
        pre = p;
        p1 = p1->next;
        p2 = p2->next;
    }
    while (p1 != NULL) {
        p = (struct ListNode *) malloc(sizeof(struct ListNode));
        p->next = NULL;
        sum = p1->val + carry;
        p->val = sum % 10;
        carry = sum / 10;
        pre->next = p;
        pre = p;
        p1 = p1->next;
    }
    while (p2 != NULL) {
        p = (struct ListNode *) malloc(sizeof(struct ListNode));
        p->next = NULL;
        sum = p2->val + carry;
        p->val = sum % 10;
        carry = sum / 10;
        pre->next = p;
        pre = p;
        p2 = p2->next;
    }
    if (carry > 0) {
        p = (struct ListNode *) malloc(sizeof(struct ListNode));
        p->val = carry;
        p->next = NULL;
        pre->next = p;
    }
    p = l->next;
    free(l);
    return p;
}
