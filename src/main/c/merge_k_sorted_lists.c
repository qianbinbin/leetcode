#include <merge_k_sorted_lists.h>
#include <stdlib.h>

static struct ListNode *merge_two_sorted_lists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode *tail = head;
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
    tail = head->next;
    free(head);
    return tail;
}

struct ListNode *mergeKLists_23(struct ListNode **lists, int listsSize) {
    if (lists == NULL || listsSize < 1) return NULL;
    int interval = 1;
    while (interval < listsSize) {
        for (int i = 0; i < listsSize - interval; i += interval * 2) {
            lists[i] = merge_two_sorted_lists(lists[i], lists[i + interval]);
        }
        interval *= 2;
    }
    return lists[0];
}
