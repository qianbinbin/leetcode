"""
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2

Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
"""

from .utils import ListNode


class Solution1:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        tail = head
        p = head.next
        while p:
            if p.val != tail.val:
                tail.next = p
                tail = p
            p = p.next
        tail.next = None
        return head
