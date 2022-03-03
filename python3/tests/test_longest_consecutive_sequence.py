from unittest import TestCase

from leetcodepy.longest_consecutive_sequence import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

NUMS1 = [100, 4, 200, 1, 3, 2]
EXPECTED1 = 4

NUMS2 = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
EXPECTED2 = 9


class TestLongestConsecutiveSequence(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.longestConsecutive(NUMS1))
        self.assertEqual(EXPECTED2, SOLUTION1.longestConsecutive(NUMS2))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.longestConsecutive(NUMS1))
        self.assertEqual(EXPECTED2, SOLUTION2.longestConsecutive(NUMS2))
