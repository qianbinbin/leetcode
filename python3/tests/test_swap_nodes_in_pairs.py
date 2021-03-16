from unittest import TestCase

from leetcodepy.swap_nodes_in_pairs import *
from leetcodepy.utils import linked_lists

SOLUTION1 = Solution1()


def HEAD1():
    return linked_lists.from_values(1, 2, 3, 4)


EXPECTED1 = linked_lists.from_values(2, 1, 4, 3)

HEAD2 = None
EXPECTED2 = None


def HEAD3():
    return linked_lists.from_values(1)


EXPECTED3 = linked_lists.from_values(1)


class TestSwapNodesInPairs(TestCase):
    def test1(self):
        self.assertTrue(linked_lists.equals(EXPECTED1, SOLUTION1.swapPairs(HEAD1())))
        self.assertTrue(linked_lists.equals(EXPECTED2, SOLUTION1.swapPairs(HEAD2)))
        self.assertTrue(linked_lists.equals(EXPECTED3, SOLUTION1.swapPairs(HEAD3())))
