from unittest import TestCase

from leetcodepy.validate_binary_search_tree import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()
SOLUTION3 = Solution3()

ROOT1 = trees.from_values(2, 1, 3)
EXPECTED1 = True

ROOT2 = trees.from_values(5, 1, 4, None, None, 3, 6)
EXPECTED2 = False


class TestValidateBinarySearchTree(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.isValidBST(ROOT1))
        self.assertEqual(EXPECTED2, SOLUTION1.isValidBST(ROOT2))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.isValidBST(ROOT1))
        self.assertEqual(EXPECTED2, SOLUTION2.isValidBST(ROOT2))

    def test3(self):
        self.assertEqual(EXPECTED1, SOLUTION3.isValidBST(ROOT1))
        self.assertEqual(EXPECTED2, SOLUTION3.isValidBST(ROOT2))
