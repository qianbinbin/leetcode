from unittest import TestCase

from leetcodepy.sum_root_to_leaf_numbers import *
from leetcodepy.utils import trees

solution1 = Solution1()

root1 = trees.from_values(1, 2, 3)

expected1 = 25

root2 = trees.from_values(4, 9, 0, 5, 1)

expected2 = 1026


class TestSumRootToLeafNumbers(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.sumNumbers(root1))
        self.assertEqual(expected2, solution1.sumNumbers(root2))
