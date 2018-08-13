from unittest import TestCase

from leetcodepy.unique_binary_search_trees import *

solution1 = Solution1()

n = 3

expected = 5


class TestUniqueBinarySearchTrees(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.numTrees(n))
