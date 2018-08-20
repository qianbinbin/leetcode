"""
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
"""
from typing import List, Optional
from .utils import ListNode


class Solution1:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if not lists:
            return None
        if len(lists) == 1:
            return lists[0]
        half = len(lists) // 2
        h1 = self.mergeKLists(lists[:half])
        h2 = self.mergeKLists(lists[half:])
        return self.merge_two_sorted_lists(h1, h2)

    @staticmethod
    def merge_two_sorted_lists(h1: Optional[ListNode], h2: Optional[ListNode]) -> Optional[ListNode]:
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
