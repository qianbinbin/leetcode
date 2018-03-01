#include <copy-list-with-random-pointer.h>
#include <stdlib.h>

struct RandomListNode *copyRandomList_138(struct RandomListNode *head) {
    if (head == NULL) return NULL;

    struct RandomListNode *copy;
    for (struct RandomListNode *p = head; p != NULL; p = copy->next) {
        copy = (struct RandomListNode *) malloc(sizeof(struct RandomListNode));
        copy->label = p->label;
        copy->next = p->next;
        p->next = copy;
    }

    for (struct RandomListNode *p = head; p != NULL; p = p->next->next) {
        p->next->random = p->random != NULL ? p->random->next : NULL;
    }

    struct RandomListNode *new = head->next;
    for (struct RandomListNode *pre = head, *p = head->next; pre != NULL; pre = pre->next, p = p->next) {
        pre->next = p->next;
        p->next = pre->next != NULL ? pre->next->next : NULL;
    }
    return new;
}
