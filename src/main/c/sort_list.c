#include "sort_list.h"

#include <stdlib.h>

static struct ListNode *merge(struct ListNode *h1, struct ListNode *h2) {
    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode)),
            *tail = dummy;
    dummy->next = NULL;
    while (h1 != NULL && h2 != NULL) {
        if (h1->val < h2->val) {
            tail->next = h1;
            h1 = h1->next;
        } else {
            tail->next = h2;
            h2 = h2->next;
        }
        tail = tail->next;
    }
    if (h1 != NULL) tail->next = h1;
    else tail->next = h2;
    struct ListNode *ret = dummy->next;
    free(dummy);
    return ret;
}

static struct ListNode *merge_sort(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *slow = dummy, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *h1 = dummy->next, *h2 = slow->next;
    free(dummy);
    slow->next = NULL;
    h1 = merge_sort(h1);
    h2 = merge_sort(h2);
    return merge(h1, h2);
}

struct ListNode *sortList_148_1(struct ListNode *head) {
    return merge_sort(head);
}
