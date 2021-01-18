"""
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
"""

from .utils import ListNode


class Solution1:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if n < 1:
            raise ValueError
        dummy = ListNode(0)
        dummy.next = head
        p = head
        while n > 0:
            p = p.next
            n -= 1
        pre = dummy
        while p:
            pre = pre.next
            p = p.next
        pre.next = pre.next.next
        return dummy.next
