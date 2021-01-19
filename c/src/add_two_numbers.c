#include "add_two_numbers.h"

#include <stdlib.h>

typedef struct ListNode node;

static node *node_create(int val) {
    node *p = (node *) malloc(sizeof(node));
    p->val = val;
    p->next = NULL;
    return p;
}

struct ListNode *addTwoNumbers_2_1(struct ListNode *l1, struct ListNode *l2) {
    node dummy = {0, NULL}, *tail = &dummy;
    int sum, carry = 0;
    for (; l1 != NULL && l2 != NULL; l1 = l1->next, l2 = l2->next) {
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        tail->next = node_create(sum % 10);
        tail = tail->next;
    }
    for (; l1 != NULL; l1 = l1->next) {
        sum = l1->val + carry;
        carry = sum / 10;
        tail->next = node_create(sum % 10);
        tail = tail->next;
    }
    for (; l2 != NULL; l2 = l2->next) {
        sum = l2->val + carry;
        carry = sum / 10;
        tail->next = node_create(sum % 10);
        tail = tail->next;
    }
    if (carry != 0)
        tail->next = node_create(carry);
    return dummy.next;
}
