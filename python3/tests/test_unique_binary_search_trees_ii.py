from unittest import TestCase

from leetcodepy.unique_binary_search_trees_ii import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()

N1 = 3
EXPECTED1 = [
    trees.from_values(1, None, 2, None, 3),
    trees.from_values(1, None, 3, 2),
    trees.from_values(2, 1, 3),
    trees.from_values(3, 1, None, None, 2),
    trees.from_values(3, 2, None, 1)
]

N2 = 1
EXPECTED2 = [
    trees.from_values(1)
]


class TestUniqueBinarySearchTreesII(TestCase):
    def test1(self):
        actual1 = SOLUTION1.generateTrees(N1)
        self.assertEqual(len(EXPECTED1), len(actual1))
        for i in range(len(EXPECTED1)):
            self.assertTrue(trees.equals(EXPECTED1[i], actual1[i]))

        actual2 = SOLUTION1.generateTrees(N2)
        self.assertEqual(len(EXPECTED2), len(actual2))
        for i in range(len(EXPECTED2)):
            self.assertTrue(trees.equals(EXPECTED2[i], actual2[i]))
