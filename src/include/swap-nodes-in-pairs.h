#ifndef LEETCODE_SWAP_NODES_IN_PAIRS_H
#define LEETCODE_SWAP_NODES_IN_PAIRS_H

#include <common.h>

/**
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *swapPairs_24(struct ListNode *head);

#endif //LEETCODE_SWAP_NODES_IN_PAIRS_H
