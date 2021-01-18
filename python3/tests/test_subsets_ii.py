from unittest import TestCase

from leetcodepy.subsets_ii import *

solution1 = Solution1()

nums = [1, 2, 2]

expected = [
    [],
    [1],
    [1, 2],
    [1, 2, 2],
    [2],
    [2, 2]
]


class TestSubsetsII(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.subsetsWithDup(nums))
