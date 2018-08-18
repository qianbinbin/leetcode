"""
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4

Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
"""
from .utils import ListNode


class Solution1:
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        dummy = ListNode(0)
        dummy.next = head
        slow, fast = dummy, dummy
        while fast is not None and fast.next is not None:
            fast = fast.next.next
            slow = slow.next
        h1, h2 = head, slow.next
        slow.next = None
        h1, h2 = self.sortList(h1), self.sortList(h2)
        return self.merge(h1, h2)

    @staticmethod
    def merge(h1: ListNode, h2: ListNode):
        if h1 is None:
            return h2
        if h2 is None:
            return h1
        dummy = ListNode(0)
        tail = dummy
        while h1 is not None and h2 is not None:
            if h1.val < h2.val:
                tail.next = h1
                h1 = h1.next
            else:
                tail.next = h2
                h2 = h2.next
            tail = tail.next
        if h1 is not None:
            tail.next = h1
        else:
            tail.next = h2
        return dummy.next
