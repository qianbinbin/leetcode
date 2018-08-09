"""
Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
"""

from .utils import ListNode


class Solution1:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        tail = dummy
        node = tail.next
        while node and node.next:
            tail.next = node.next
            node.next = tail.next.next
            tail.next.next = node
            tail = node
            node = tail.next
        return dummy.next
