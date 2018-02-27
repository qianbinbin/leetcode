#ifndef LEETCODE_REVERSE_LINKED_LIST_II_H
#define LEETCODE_REVERSE_LINKED_LIST_II_H

#include <common.h>

/**
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseBetween_92(struct ListNode *head, int m, int n);

#endif //LEETCODE_REVERSE_LINKED_LIST_II_H
