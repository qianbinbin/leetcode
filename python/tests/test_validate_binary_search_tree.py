from unittest import TestCase

from leetcodepy.validate_binary_search_tree import *
from leetcodepy.utils import trees

solution1 = Solution1()

root1 = trees.from_values(2, 1, 3)

root2 = trees.from_values(5, 1, 4, None, None, 3, 6)


class TestValidateBinarySearchTree(TestCase):
    def test1(self):
        self.assertTrue(solution1.isValidBST(root1))
        self.assertFalse(solution1.isValidBST(root2))
