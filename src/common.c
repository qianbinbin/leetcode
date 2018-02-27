#include <stdio.h>
#include <common.h>
#include <stdlib.h>

void print_array(int *nums, int numsSize) {
    if (nums == NULL) return;
    printf("{");
    for (int i = 0; i < numsSize; ++i) {
        if (i < numsSize - 1) printf("%d, ", nums[i]);
        else printf("%d", nums[numsSize - 1]);
    }
    printf("}\n");
}

void print_list(struct ListNode *p) {
    while (p != NULL) {
        if (p->next != NULL) printf("%d->", p->val);
        else printf("%d", p->val);
        p = p->next;
    }
    printf("\n");
}

struct ListNode *append_list(struct ListNode *p, int val) {
    struct ListNode *tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
    tmp->val = val;
    tmp->next = NULL;
    p->next = tmp;
    return tmp;
}

struct ListNode *array_to_list(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return NULL;

    struct ListNode *list = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *p = list;
    for (int i = 0; i < numsSize; ++i) {
        p = append_list(p, nums[i]);
    }
    p = list->next;
    free(list);
    return p;
}

void free_list(struct ListNode *p) {
    struct ListNode *pre;
    while (p != NULL) {
        pre = p;
        p = pre->next;
        free(pre);
    }
}
