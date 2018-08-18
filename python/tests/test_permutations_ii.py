from unittest import TestCase

from leetcodepy.permutations_ii import *

solution1 = Solution1()

nums = [1, 1, 2]

expected = [
    [1, 1, 2],
    [1, 2, 1],
    [2, 1, 1]
]


class TestPermutationsII(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.permuteUnique(nums))
