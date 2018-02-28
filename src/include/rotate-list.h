#ifndef LEETCODE_ROTATE_LIST_H
#define LEETCODE_ROTATE_LIST_H

#include <common.h>

/**
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 *
 * Example:
 *
 * Given 1->2->3->4->5->NULL and k = 2,
 *
 * return 4->5->1->2->3->NULL.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *rotateRight_61(struct ListNode *head, int k);

#endif //LEETCODE_ROTATE_LIST_H
