"""
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.



Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:

Input: lists = []
Output: []

Example 3:

Input: lists = [[]]
Output: []


Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
"""
from heapq import heappush, heappop
from typing import List, Optional

from .utils import ListNode


class Solution1:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
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
        dummy = ListNode()
        tail = dummy
        while h1 and h2:
            if h1.val <= h2.val:
                tail.next = h1
                tail = h1
                h1 = h1.next
            else:
                tail.next = h2
                tail = h2
                h2 = h2.next
        tail.next = h1 if h1 else h2
        return dummy.next


class Solution2:
    class NodeWrapper:
        def __init__(self, node: ListNode):
            self.node = node

        def __lt__(self, other):
            return self.node.val < other.node.val

    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        heap = []
        for node in lists:
            if node:
                heappush(heap, self.NodeWrapper(node))

        dummy = ListNode()
        tail = dummy
        while heap:
            tail.next = heappop(heap).node
            tail = tail.next
            if tail.next:
                heappush(heap, self.NodeWrapper(tail.next))
        return dummy.next
