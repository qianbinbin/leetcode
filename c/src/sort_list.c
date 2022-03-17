#include "sort_list.h"

#include <stdlib.h>

static struct ListNode *merge(struct ListNode *h1, struct ListNode *h2) {
    struct ListNode dummy = {}, *tail = &dummy;
    while (h1 != NULL && h2 != NULL) {
        if (h1->val < h2->val) {
            tail = tail->next = h1;
            h1 = h1->next;
        } else {
            tail = tail->next = h2;
            h2 = h2->next;
        }
    }
    tail->next = h1 != NULL ? h1 : h2;
    return dummy.next;
}

static struct ListNode *merge_sort(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode dummy = {0, head};
    struct ListNode *slow = &dummy, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *h1 = dummy.next, *h2 = slow->next;
    slow->next = NULL;
    h1 = merge_sort(h1);
    h2 = merge_sort(h2);
    return merge(h1, h2);
}

struct ListNode *sortList_148_1(struct ListNode *head) {
    return merge_sort(head);
}
