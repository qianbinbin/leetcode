#include <insertion_sort_list.h>
#include <stdlib.h>

struct ListNode *insertionSortList_147(struct ListNode *head) {
    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *tail = dummy, *pre;
    struct ListNode *cur = tail->next;
    while (cur != NULL) {
        pre = dummy;
        while (pre != tail && pre->next->val < cur->val) pre = pre->next;
        if (pre != tail) {
            tail->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
        } else {
            tail = cur;
        }
        cur = tail->next;
    }
    head = dummy->next;
    free(dummy);
    return head;
}
