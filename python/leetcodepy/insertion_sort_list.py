"""
Sort a linked list using insertion sort.

https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif

A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list


Algorithm of Insertion Sort:

1. Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
2. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
3. It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4

Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
"""
from .utils import ListNode


class Solution1:
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return
        dummy = ListNode(0)
        dummy.next = head
        tail, node = head, head.next
        while node is not None:
            if node.val >= tail.val:
                tail = node
                node = node.next
                continue
            tail.next = node.next
            pre, p = dummy, dummy.next
            while pre is not tail and p.val <= node.val:
                pre = p
                p = p.next
            node.next = p
            pre.next = node
            node = tail.next
        return dummy.next
