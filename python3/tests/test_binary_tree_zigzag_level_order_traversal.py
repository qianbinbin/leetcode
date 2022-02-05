from unittest import TestCase

from leetcodepy.binary_tree_zigzag_level_order_traversal import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

ROOT1 = trees.from_values(3, 9, 20, None, None, 15, 7)
EXPECTED1 = [
    [3],
    [20, 9],
    [15, 7]
]

ROOT2 = trees.from_values(1)
EXPECTED2 = [[1]]

ROOT3 = trees.from_values()
EXPECTED3 = []


class TestBinaryTreeZigzagLevelOrderTraversal(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.zigzagLevelOrder(ROOT1))
        self.assertListEqual(EXPECTED2, SOLUTION1.zigzagLevelOrder(ROOT2))
        self.assertListEqual(EXPECTED3, SOLUTION1.zigzagLevelOrder(ROOT3))

    def test2(self):
        self.assertListEqual(EXPECTED1, SOLUTION2.zigzagLevelOrder(ROOT1))
        self.assertListEqual(EXPECTED2, SOLUTION2.zigzagLevelOrder(ROOT2))
        self.assertListEqual(EXPECTED3, SOLUTION2.zigzagLevelOrder(ROOT3))
