from unittest import TestCase

from leetcodepy.unique_binary_search_trees_ii import *
from leetcodepy.utils import trees

solution1 = Solution1()

n = 3

expected = [
    trees.from_values(1, None, 2, None, 3),
    trees.from_values(1, None, 3, 2),
    trees.from_values(2, 1, 3),
    trees.from_values(3, 1, None, None, 2),
    trees.from_values(3, 2, None, 1)
]


class TestUniqueBinarySearchTreesII(TestCase):
    def test1(self):
        actual = solution1.generateTrees(n)
        self.assertEqual(len(expected), len(actual))
        for i in range(len(expected)):
            self.assertTrue(trees.equals(expected[i], actual[i]))
