from unittest import TestCase

from leetcodepy.merge_k_sorted_lists import *
from leetcodepy.utils import linked_lists

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()


def LISTS1():
    return [linked_lists.from_values(1, 4, 5), linked_lists.from_values(1, 3, 4), linked_lists.from_values(2, 6)]


EXPECTED1 = linked_lists.from_values(1, 1, 2, 3, 4, 4, 5, 6)

LISTS2 = []
EXPECTED2 = None

LISTS3 = [None]
EXPECTED3 = None


class TestMergeKSortedLists(TestCase):
    def test1(self):
        self.assertTrue(linked_lists.equals(EXPECTED1, SOLUTION1.mergeKLists(LISTS1())))
        self.assertTrue(linked_lists.equals(EXPECTED2, SOLUTION1.mergeKLists(LISTS2)))
        self.assertTrue(linked_lists.equals(EXPECTED3, SOLUTION1.mergeKLists(LISTS3)))

    def test2(self):
        self.assertTrue(linked_lists.equals(EXPECTED1, SOLUTION2.mergeKLists(LISTS1())))
        self.assertTrue(linked_lists.equals(EXPECTED2, SOLUTION2.mergeKLists(LISTS2)))
        self.assertTrue(linked_lists.equals(EXPECTED3, SOLUTION2.mergeKLists(LISTS3)))
