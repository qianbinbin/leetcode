from unittest import TestCase

from leetcodepy.minimum_depth_of_binary_tree import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

ROOT1 = trees.from_values(3, 9, 20, None, None, 15, 7)
EXPECTED1 = 2

ROOT2 = trees.from_values(2, None, 3, None, 4, None, 5, None, 6)
EXPECTED2 = 5


class TestMinimumDepthOfBinaryTree(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.minDepth(ROOT1))
        self.assertEqual(EXPECTED2, SOLUTION1.minDepth(ROOT2))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.minDepth(ROOT1))
        self.assertEqual(EXPECTED2, SOLUTION2.minDepth(ROOT2))
