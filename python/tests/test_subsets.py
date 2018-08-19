from unittest import TestCase

from leetcodepy.subsets import *

solution1 = Solution1()

nums = [1, 2, 3]

expected = [
    [],
    [1],
    [1, 2],
    [1, 2, 3],
    [1, 3],
    [2],
    [2, 3],
    [3]
]


class TestSubsets(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.subsets(nums))
