from unittest import TestCase

from leetcodepy.reverse_linked_list_ii import *
from leetcodepy.utils import linked_lists

SOLUTION1 = Solution1()


def HEAD1():
    return linked_lists.from_values(1, 2, 3, 4, 5)


LEFT1, RIGHT1 = 2, 4
EXPECTED1 = linked_lists.from_values(1, 4, 3, 2, 5)


def HEAD2():
    return linked_lists.from_values(5)


LEFT2, RIGHT2 = 1, 1
EXPECTED2 = linked_lists.from_values(5)


class TestReverseLinkedListII(TestCase):
    def test1(self):
        self.assertTrue(linked_lists.equals(EXPECTED1, SOLUTION1.reverseBetween(HEAD1(), LEFT1, RIGHT1)))
        self.assertTrue(linked_lists.equals(EXPECTED2, SOLUTION1.reverseBetween(HEAD2(), LEFT2, RIGHT2)))
