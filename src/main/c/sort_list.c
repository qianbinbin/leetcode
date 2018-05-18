#include <sort_list.h>
#include <stdlib.h>

/**
 * @return Tail of list after merged
 */
static struct ListNode *merge_and_return_tail(struct ListNode *l1, struct ListNode *l2, struct ListNode *tail) {
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 != NULL ? l1 : l2;
    while (tail->next != NULL) tail = tail->next;
    return tail;
}

static struct ListNode *split_list(struct ListNode *head, int n) {
    struct ListNode *tail = head;
    for (int i = 0; tail != NULL && i < n - 1; ++i)
        tail = tail->next;
    struct ListNode *ret = tail;
    if (tail != NULL) {
        ret = tail->next;
        tail->next = NULL;
    }
    return ret;
}

static int list_length(struct ListNode *head) {
    int count = 0;
    while (head != NULL) {
        ++count;
        head = head->next;
    }
    return count;
}

struct ListNode *sortList_148(struct ListNode *head) {
    int length = list_length(head);

    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = head;
    int interval = 1;
    struct ListNode *tail, *l1, *l2, *cur;
    while (interval < length) {
        tail = dummy;
        l1 = dummy->next;
        l2 = split_list(l1, interval);
        cur = split_list(l2, interval);
        while (l1 != NULL) {
            tail = merge_and_return_tail(l1, l2, tail);
            tail->next = cur;
            l1 = cur;
            l2 = split_list(cur, interval);
            cur = split_list(l2, interval);
        }
        interval *= 2;
    }
    struct ListNode *ret = dummy->next;
    free(dummy);
    return ret;
}
