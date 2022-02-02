from unittest import TestCase

from leetcodepy.unique_binary_search_trees import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution1()

N1 = 3
EXPECTED1 = 5

N2 = 1
EXPECTED2 = 1


class TestUniqueBinarySearchTrees(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.numTrees(N1))
        self.assertEqual(EXPECTED2, SOLUTION1.numTrees(N2))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.numTrees(N1))
        self.assertEqual(EXPECTED2, SOLUTION2.numTrees(N2))
