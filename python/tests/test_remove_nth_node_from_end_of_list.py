from unittest import TestCase

from leetcodepy.remove_nth_node_from_end_of_list import *
from leetcodepy.utils import linked_lists

solution1 = Solution1()

values = (1, 2, 3, 4, 5)

n = 2

expected = linked_lists.from_values(1, 2, 3, 5)


class TestRemoveNthNodeFromEndOfList(TestCase):
    def test1(self):
        head = linked_lists.from_values(*values)
        head = solution1.removeNthFromEnd(head, n)
        self.assertTrue(linked_lists.equals(expected, head))
