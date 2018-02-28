#ifndef LEETCODE_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
#define LEETCODE_REMOVE_NTH_NODE_FROM_END_OF_LIST_H

#include <common.h>

/**
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 *    Given linked list: 1->2->3->4->5, and n = 2.
 *
 *    After removing the second node from the end, the linked list becomes 1->2->3->5.
 *
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeNthFromEnd_19(struct ListNode *head, int n);

#endif //LEETCODE_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
