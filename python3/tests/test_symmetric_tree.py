from unittest import TestCase

from leetcodepy.symmetric_tree import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

ROOT1 = trees.from_values(1, 2, 2, 3, 4, 4, 3)
EXPECTED1 = True

ROOT2 = trees.from_values(1, 2, 2, None, 3, None, 3)
EXPECTED2 = False


class TestSymmetricTree(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.isSymmetric(ROOT1))
        self.assertEqual(EXPECTED2, SOLUTION1.isSymmetric(ROOT2))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.isSymmetric(ROOT1))
        self.assertEqual(EXPECTED2, SOLUTION2.isSymmetric(ROOT2))
