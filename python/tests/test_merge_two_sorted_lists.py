from unittest import TestCase

from leetcodepy.merge_two_sorted_lists import *
from leetcodepy.utils import linked_lists

solution1 = Solution1()

values1 = (1, 2, 4)

values2 = (1, 3, 4)

expected = linked_lists.from_values(1, 1, 2, 3, 4, 4)


class TestMergeTwoSortedLists(TestCase):
    def test1(self):
        l1 = linked_lists.from_values(*values1)
        l2 = linked_lists.from_values(*values2)
        head = solution1.mergeTwoLists(l1, l2)
        self.assertTrue(linked_lists.equals(expected, head))
