"""
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

All inputs will be in lowercase.
The order of your output does not matter.
"""
from collections import defaultdict
from typing import List


class Solution1:
    class Anagram:
        def __init__(self, s: str):
            counts = [0] * 26
            for ch in s:
                counts[ord(ch) - 97] += 1
            self.__counts = counts
            self.__hash = 0

        def __eq__(self, other):
            if not isinstance(other, self.__class__):
                return False
            if self.__hash != 0 and other.__hash != 0 and self.__hash != other.__hash:
                return False
            for i in range(26):
                if self.__counts[i] != other.__counts[i]:
                    return False
            return True

        def __hash__(self):
            if self.__hash != 0:
                return self.__hash
            result = 0
            for count in self.__counts:
                result = result * 31 + count
            self.__hash = result
            return result

    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        result = defaultdict(lambda: [])
        for s in strs:
            result[self.Anagram(s)].append(s)
        return list(result.values())
