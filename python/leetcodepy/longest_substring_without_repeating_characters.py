"""
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
"""


class Solution1:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        start = -1
        hash_map = {}
        for i, ch in enumerate(s):
            if ch in hash_map:
                start = max(start, hash_map[ch])
            result = max(result, i - start)
            hash_map[ch] = i
        return result
