from unittest import TestCase

from leetcodepy.longest_consecutive_sequence import *

solution1 = Solution1()

nums = [100, 4, 200, 1, 3, 2]

expected = 4


class TestLongestConsecutiveSequence(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.longestConsecutive(nums))
