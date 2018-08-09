"""
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:

Input: 1->1->1->2->3
Output: 2->3
"""

from .utils import ListNode


class Solution1:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        tail = dummy
        p = head
        while p:
            if not p.next or p.val != p.next.val:
                tail.next = p
                tail = tail.next
                p = p.next
            else:
                skip = p.val
                while p and p.val == skip:
                    p = p.next
        tail.next = None
        return dummy.next
