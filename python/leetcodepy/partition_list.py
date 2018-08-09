"""
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
"""

from .utils import ListNode


class Solution1:
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        dummy1 = ListNode(0)
        dummy1.next = head
        dummy2 = ListNode(0)
        tail = dummy2
        pre, p = dummy1, head
        while p:
            if p.val < x:
                pre.next = p.next
                tail.next = p
                tail = p
                p = pre.next
            else:
                pre = p
                p = p.next
        tail.next = dummy1.next
        return dummy2.next
