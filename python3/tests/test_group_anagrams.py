from unittest import TestCase

from leetcodepy.group_anagrams import *

solution1 = Solution1()

strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

expected = [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']]


class TestGroupAnagrams(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.groupAnagrams(strs))
