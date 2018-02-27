#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

void print_array(int *nums, int numsSize);

struct ListNode {
    int val;
    struct ListNode *next;
};

void print_list(struct ListNode *p);

struct ListNode *append_list(struct ListNode *p, int val);

struct ListNode *array_to_list(int *nums, int numsSize);

void free_list(struct ListNode *p);

#endif //LEETCODE_COMMON_H
