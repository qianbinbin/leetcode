"""
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
"""

from .utils import ListNode


class Solution1:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if k < 1:
            raise ValueError("k must be a positive integer")
        dummy = ListNode(0)
        dummy.next = head
        tail = dummy
        while True:
            first, end = tail.next, tail.next
            i = 0
            while i < k and end:
                end = end.next
                i += 1
            if i < k:
                break
            pre, p = first, first.next
            while p != end:
                pre.next = p.next
                p.next = first
                tail.next = p
                first = p
                p = pre.next
            tail = pre
        return dummy.next
