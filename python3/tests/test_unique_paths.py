from unittest import TestCase

from leetcodepy.unique_paths import *

solution1 = Solution1()

solution2 = Solution2()

m1 = 3

n1 = 2

expected1 = 3

m2 = 7

n2 = 3

expected2 = 28


class TestUniquePaths(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.uniquePaths(m1, n1))
        self.assertEqual(expected2, solution1.uniquePaths(m2, n2))

    def test2(self):
        self.assertEqual(expected1, solution2.uniquePaths(m1, n1))
        self.assertEqual(expected2, solution2.uniquePaths(m2, n2))
