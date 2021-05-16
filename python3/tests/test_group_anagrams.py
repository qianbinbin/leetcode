from unittest import TestCase

from leetcodepy.group_anagrams import *

SOLUTION1 = Solution1()

STRS1 = ["eat", "tea", "tan", "ate", "nat", "bat"]
EXPECTED1 = [["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]

STRS2 = [""]
EXPECTED2 = [[""]]

STRS3 = ["a"]
EXPECTED3 = [["a"]]


class TestGroupAnagrams(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.groupAnagrams(STRS1))
        self.assertListEqual(EXPECTED2, SOLUTION1.groupAnagrams(STRS2))
        self.assertListEqual(EXPECTED3, SOLUTION1.groupAnagrams(STRS3))
