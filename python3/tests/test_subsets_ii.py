from unittest import TestCase

from leetcodepy.subsets_ii import *

SOLUTION1 = Solution1()


def NUMS1():
    return [1, 2, 2]


EXPECTED1 = [
    [],
    [1],
    [1, 2],
    [1, 2, 2],
    [2],
    [2, 2]
]


def NUMS2():
    return [0]


EXPECTED2 = [
    [],
    [0]
]


class TestSubsetsII(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.subsetsWithDup(NUMS1()))
        self.assertListEqual(EXPECTED2, SOLUTION1.subsetsWithDup(NUMS2()))
