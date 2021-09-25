from unittest import TestCase

from leetcodepy.unique_paths import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

M1 = 3
N1 = 7
EXPECTED1 = 28

M2 = 3
N2 = 2
EXPECTED2 = 3

M3 = 7
N3 = 3
EXPECTED3 = 28

M4 = 3
N4 = 3
EXPECTED4 = 6


class TestUniquePaths(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.uniquePaths(M1, N1))
        self.assertEqual(EXPECTED2, SOLUTION1.uniquePaths(M2, N2))
        self.assertEqual(EXPECTED3, SOLUTION1.uniquePaths(M3, N3))
        self.assertEqual(EXPECTED4, SOLUTION1.uniquePaths(M4, N4))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.uniquePaths(M1, N1))
        self.assertEqual(EXPECTED2, SOLUTION2.uniquePaths(M2, N2))
        self.assertEqual(EXPECTED3, SOLUTION2.uniquePaths(M3, N3))
        self.assertEqual(EXPECTED4, SOLUTION2.uniquePaths(M4, N4))
