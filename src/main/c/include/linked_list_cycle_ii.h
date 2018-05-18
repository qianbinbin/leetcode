#ifndef LEETCODE_LINKED_LIST_CYCLE_II_H
#define LEETCODE_LINKED_LIST_CYCLE_II_H

#include <common.h>

/**
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * Note: Do not modify the linked list.
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
struct ListNode *detectCycle_142(struct ListNode *head);

#endif //LEETCODE_LINKED_LIST_CYCLE_II_H
