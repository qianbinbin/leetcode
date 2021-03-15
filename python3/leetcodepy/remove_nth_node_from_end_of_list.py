"""
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?



Example 1:

https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]


Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
"""

from .utils import ListNode


class Solution1:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0, head)
        slow, fast = dummy, dummy
        while n >= 0:
            fast = fast.next
            n -= 1
        while fast:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return dummy.next
