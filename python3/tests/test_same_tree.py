from unittest import TestCase

from leetcodepy.same_tree import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()

P1, Q1 = trees.from_values(1, 2, 3), trees.from_values(1, 2, 3)
EXPECTED1 = True

P2, Q2 = trees.from_values(1, 2), trees.from_values(1, None, 2)
EXPECTED2 = False

P3, Q3 = trees.from_values(1, 2, 1), trees.from_values(1, 1, 2)
EXPECTED3 = False


class TestSameTree(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.isSameTree(P1, Q1))
        self.assertEqual(EXPECTED2, SOLUTION1.isSameTree(P2, Q2))
        self.assertEqual(EXPECTED3, SOLUTION1.isSameTree(P3, Q3))
