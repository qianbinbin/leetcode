#include "add_two_numbers.h"

#include <stdlib.h>

typedef struct ListNode lnode;

static lnode *lnode_create(int val) {
    lnode *node = (lnode *) malloc(sizeof(lnode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode *addTwoNumbers_2_1(struct ListNode *l1, struct ListNode *l2) {
    if (l1 == NULL && l2 == NULL) return NULL;

    lnode *dummy = lnode_create(0);
    lnode *tail = dummy;
    int sum, carry = 0;
    while (l1 != NULL && l2 != NULL) {
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        tail->next = lnode_create(sum % 10);
        tail = tail->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL) {
        sum = l1->val + carry;
        carry = sum / 10;
        tail->next = lnode_create(sum % 10);
        tail = tail->next;
        l1 = l1->next;
    }
    while (l2 != NULL) {
        sum = l2->val + carry;
        carry = sum / 10;
        tail->next = lnode_create(sum % 10);
        tail = tail->next;
        l2 = l2->next;
    }
    if (carry > 0) {
        tail->next = lnode_create(carry);
    }
    lnode *l = dummy->next;
    free(dummy);
    return l;
}
