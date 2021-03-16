"""
Given a linked list, swap every two adjacent nodes and return its head.



Example 1:

https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg

Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:

Input: head = []
Output: []

Example 3:

Input: head = [1]
Output: [1]


Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100


Follow up: Can you solve the problem without modifying the values in the list's nodes? (i.e., Only nodes themselves may be changed.)
"""

from .utils import ListNode


class Solution1:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy = ListNode(0, head)
        tail, p1, p2 = dummy, head, None
        while p1 and p1.next:
            p2 = p1.next
            p1.next = p2.next
            p2.next = p1
            tail.next = p2
            tail = p1
            p1 = p1.next
        return dummy.next
