#ifndef LEETCODE_COPY_LIST_WITH_RANDOM_POINTER_H
#define LEETCODE_COPY_LIST_WITH_RANDOM_POINTER_H

struct RandomListNode {
    int label;
    struct RandomListNode *next;
    struct RandomListNode *random;
};

/**
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 *
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList_138(struct RandomListNode *head);

#endif //LEETCODE_COPY_LIST_WITH_RANDOM_POINTER_H
