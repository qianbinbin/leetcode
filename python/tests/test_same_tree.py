from unittest import TestCase

from leetcodepy.same_tree import *
from leetcodepy.utils import trees

solution1 = Solution1()

root11, root12 = trees.from_values(1, 2, 3), trees.from_values(1, 2, 3)

root21, root22 = trees.from_values(1, 2), trees.from_values(1, None, 2)

root31, root32 = trees.from_values(1, 2, 1), trees.from_values(1, 1, 2)


class TestSameTree(TestCase):
    def test1(self):
        self.assertTrue(solution1.isSameTree(root11, root12))
        self.assertFalse(solution1.isSameTree(root21, root22))
        self.assertFalse(solution1.isSameTree(root31, root32))
