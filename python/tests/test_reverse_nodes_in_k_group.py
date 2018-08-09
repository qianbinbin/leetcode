from unittest import TestCase

from leetcodepy.reverse_nodes_in_k_group import *
from leetcodepy.utils import linked_lists

solution1 = Solution1()

values = (1, 2, 3, 4, 5)

k1, k2 = 2, 3

expected1 = linked_lists.from_values(2, 1, 4, 3, 5)

expected2 = linked_lists.from_values(3, 2, 1, 4, 5)


class TestReverseNodesInKGroup(TestCase):
    def test1(self):
        head = linked_lists.from_values(*values)
        head = solution1.reverseKGroup(head, 2)
        self.assertTrue(linked_lists.equals(expected1, head))

        head = linked_lists.from_values(*values)
        head = solution1.reverseKGroup(head, 3)
        self.assertTrue(linked_lists.equals(expected2, head))
