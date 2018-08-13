from unittest import TestCase

from leetcodepy.symmetric_tree import *
from leetcodepy.utils import trees

solution1 = Solution1()

root1 = trees.from_values(1, 2, 2, 3, 4, 4, 3)

root2 = trees.from_values(1, 2, 2, None, 3, None, 3)


class TestSymmetricTree(TestCase):
    def test1(self):
        self.assertTrue(solution1.isSymmetric(root1))
        self.assertFalse(solution1.isSymmetric(root2))
