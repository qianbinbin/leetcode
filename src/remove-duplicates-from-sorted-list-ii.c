#include <remove-duplicates-from-sorted-list-ii.h>
#include <stdlib.h>

struct ListNode *deleteDuplicates_82(struct ListNode *head) {
    if (head == NULL) return NULL;

    struct ListNode *list = (struct ListNode *) malloc(sizeof(struct ListNode));
    list->next = head;
    struct ListNode *pre = list, *p = head, *rm;
    while (p != NULL) {
        if (p->next != NULL && p->val == p->next->val) {
            rm = pre->next;
            p = rm->next;
            while (p != NULL && p->val == rm->val) {
                rm->next = p->next;
                free(p);
                p = rm->next;
            }
            pre->next = p;
            free(rm);
        } else {
            pre = p;
            p = p->next;
        }
    }
    head = list->next;
    free(list);
    return head;
}
