#ifndef LEETCODE_LINKED_LIST_CYCLE_H
#define LEETCODE_LINKED_LIST_CYCLE_H

#include <common.h>
#include <stdbool.h>

/**
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle_141(struct ListNode *head);

#endif //LEETCODE_LINKED_LIST_CYCLE_H
