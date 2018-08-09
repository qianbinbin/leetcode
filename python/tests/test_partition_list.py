from unittest import TestCase

from leetcodepy.partition_list import *
from leetcodepy.utils import linked_lists

solution1 = Solution1()

values = (1, 4, 3, 2, 5, 2)

x = 3

expected = linked_lists.from_values(1, 2, 2, 4, 3, 5)


class TestPartitionList(TestCase):
    def test1(self):
        head = linked_lists.from_values(*values)
        head = solution1.partition(head, 3)
        self.assertTrue(linked_lists.equals(expected, head))
