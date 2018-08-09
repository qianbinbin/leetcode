"""
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
"""

from .utils import ListNode


class Solution1:
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if m < 1 or m > n:
            raise ValueError("1 ≤ m ≤ n ≤ length of list")
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        for i in range(m - 1):
            pre = pre.next
        first = pre.next
        for i in range(m, n):
            p = first.next
            first.next = p.next
            p.next = pre.next
            pre.next = p
        return dummy.next
