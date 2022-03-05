from unittest import TestCase

from leetcodepy.sum_root_to_leaf_numbers import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()

ROOT1 = trees.from_values(1, 2, 3)
EXPECTED1 = 25

ROOT2 = trees.from_values(4, 9, 0, 5, 1)
EXPECTED2 = 1026


class TestSumRootToLeafNumbers(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.sumNumbers(ROOT1))
        self.assertEqual(EXPECTED2, SOLUTION1.sumNumbers(ROOT2))
