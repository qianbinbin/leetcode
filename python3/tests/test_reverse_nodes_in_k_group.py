from unittest import TestCase

from leetcodepy.reverse_nodes_in_k_group import *
from leetcodepy.utils import linked_lists

SOLUTION1 = Solution1()


def HEAD1():
    return linked_lists.from_values(1, 2, 3, 4, 5)


K1 = 2
EXPECTED1 = linked_lists.from_values(2, 1, 4, 3, 5)


def HEAD2():
    return linked_lists.from_values(1, 2, 3, 4, 5)


K2 = 3
EXPECTED2 = linked_lists.from_values(3, 2, 1, 4, 5)


def HEAD3():
    return linked_lists.from_values(1, 2, 3, 4, 5)


K3 = 1
EXPECTED3 = linked_lists.from_values(1, 2, 3, 4, 5)


def HEAD4():
    return linked_lists.from_values(1)


K4 = 1
EXPECTED4 = linked_lists.from_values(1)


class TestReverseNodesInKGroup(TestCase):
    def test1(self):
        self.assertTrue(linked_lists.equals(EXPECTED1, SOLUTION1.reverseKGroup(HEAD1(), K1)))
        self.assertTrue(linked_lists.equals(EXPECTED2, SOLUTION1.reverseKGroup(HEAD2(), K2)))
        self.assertTrue(linked_lists.equals(EXPECTED3, SOLUTION1.reverseKGroup(HEAD3(), K3)))
        self.assertTrue(linked_lists.equals(EXPECTED4, SOLUTION1.reverseKGroup(HEAD4(), K4)))
