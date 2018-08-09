from unittest import TestCase

from leetcodepy.swap_nodes_in_pairs import *
from leetcodepy.utils import linked_lists

solution1 = Solution1()

values = (1, 2, 3, 4)

expected = linked_lists.from_values(2, 1, 4, 3)


class TestSwapNodesInPairs(TestCase):
    def test1(self):
        head = linked_lists.from_values(*values)
        head = solution1.swapPairs(head)
        self.assertTrue(linked_lists.equals(expected, head))
