from unittest import TestCase

from leetcodepy.merge_k_sorted_lists import *
from leetcodepy.utils import linked_lists

solution1 = Solution1()

values_lists = [
    (1, 4, 5),
    (1, 3, 4),
    (2, 6)
]

expected = linked_lists.from_values(1, 1, 2, 3, 4, 4, 5, 6)


class TestMergeKSortedLists(TestCase):
    def test1(self):
        lists = [linked_lists.from_values(*values) for values in values_lists]
        self.assertTrue(linked_lists.equals(expected, solution1.mergeKLists(lists)))
