"""
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().



Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

Example 3:

Input: haystack = "", needle = ""
Output: 0


Constraints:

0 <= haystack.length, needle.length <= 5 * 10^4
haystack and needle consist of only lower-case English characters.
"""


class Solution1:
    def strStr(self, haystack: str, needle: str) -> int:
        size1, size2 = len(haystack), len(needle)
        if size1 < size2:
            return -1
        if size2 == 0:
            return 0
        i, j = 0, 0
        while i < size1 and j < size2:
            if haystack[i] != needle[j]:
                i = i - j + 1
                j = 0
            else:
                i += 1
                j += 1
        return i - j if j == size2 else -1


class Solution2:
    @staticmethod
    def _get_next(s: str) -> list:
        _next = [0] * len(s)
        _next[0] = -1
        i, j = 0, -1
        while i < len(s) - 1:
            while j != -1 and s[i] != s[j]:
                j = _next[j]
            i += 1
            j += 1
            _next[i] = _next[j] if s[i] == s[j] else j
        return _next

    def strStr(self, haystack: str, needle: str) -> int:
        size1, size2 = len(haystack), len(needle)
        if size1 < size2:
            return -1
        if size2 == 0:
            return 0
        _next = self._get_next(needle)
        i, j = 0, 0
        while i < size1 and j < size2:
            while j != -1 and haystack[i] != needle[j]:
                j = _next[j]
            i += 1
            j += 1
        return i - j if j == size2 else -1
