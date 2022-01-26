from unittest import TestCase

from leetcodepy.partition_list import *
from leetcodepy.utils import linked_lists

SOLUTION1 = Solution1()

HEAD1 = linked_lists.from_values(1, 4, 3, 2, 5, 2)
X1 = 3
EXPECTED1 = linked_lists.from_values(1, 2, 2, 4, 3, 5)

HEAD2 = linked_lists.from_values(2, 1)
X2 = 2
EXPECTED2 = linked_lists.from_values(1, 2)


class TestPartitionList(TestCase):
    def test1(self):
        self.assertTrue(linked_lists.equals(EXPECTED1, SOLUTION1.partition(HEAD1, X1)))
        self.assertTrue(linked_lists.equals(EXPECTED2, SOLUTION1.partition(HEAD2, X2)))
