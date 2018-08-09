"""
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
"""
from collections import defaultdict

from .utils import RandomListNode


class Solution1(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        def_dict = defaultdict(lambda: RandomListNode(0))
        def_dict[None] = None
        p = head
        while p:
            def_dict[p].label = p.label
            def_dict[p].next = def_dict[p.next]
            def_dict[p].random = def_dict[p.random]
            p = p.next
        return def_dict[head]


class Solution2(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        if not head:
            return None
        p = head
        while p:
            q = RandomListNode(p.label)
            q.next = p.next
            p.next = q
            p = q.next
        p = head
        while p:
            if p.random:
                p.next.random = p.random.next
            p = p.next.next
        result = head.next
        p = head
        while p:
            q = p.next
            p.next = q.next
            q.next = None if not q.next else q.next.next
            p = p.next
        return result
