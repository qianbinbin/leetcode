"""
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
"""

from .utils import ListNode


class Solution1:
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        if not head:
            return
        dummy1 = ListNode(0)
        dummy1.next = head
        slow, fast = dummy1, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        dummy2 = ListNode(0)
        dummy2.next = slow.next
        slow.next = None

        first = dummy2.next
        p = first.next
        while p:
            first.next = p.next
            p.next = dummy2.next
            dummy2.next = p
            p = first.next

        dummy = ListNode(0)
        tail = dummy
        n1, n2 = dummy1.next, dummy2.next
        while n1:
            tail.next = n1
            tail = n1
            n1 = n1.next
            tail.next = n2
            tail = n2
            n2 = n2.next
        tail.next = n2
