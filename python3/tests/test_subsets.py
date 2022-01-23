from unittest import TestCase

from leetcodepy.subsets import *

SOLUTION1 = Solution1()


def NUMS1():
    return [1, 2, 3]


EXPECTED1 = [
    [],
    [1],
    [1, 2],
    [1, 2, 3],
    [1, 3],
    [2],
    [2, 3],
    [3]
]


def NUMS2():
    return [0]


EXPECTED2 = [
    [],
    [0]
]


class TestSubsets(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.subsets(NUMS1()))
        self.assertListEqual(EXPECTED2, SOLUTION1.subsets(NUMS2()))
