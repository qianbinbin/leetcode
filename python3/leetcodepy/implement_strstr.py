"""
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
"""


class Solution1:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        size1, size2 = len(haystack), len(needle)
        if size1 < size2:
            return -1
        if size2 == 0:
            return 0
        i, j = 0, 0
        while i <= size1 - size2:
            j = 0
            while j < size2:
                if haystack[i + j] != needle[j]:
                    i += 1
                    break
                else:
                    j += 1
            if j == size2:
                return i
        return -1


class Solution2:
    @staticmethod
    def generate_next(s: str) -> list:
        result = [0] * len(s)
        if not s:
            return result
        result[0] = -1
        i, j = 1, -1
        while i < len(s):
            if j == -1:
                if s[i] == s[0]:
                    result[i] = -1
                else:
                    result[i] = 0
                i += 1
                j = 0
            elif s[i - 1] == s[j]:
                j += 1
                if s[i] == s[j]:
                    result[i] = result[j]
                    i += 1
                else:
                    result[i] = j
                    i += 1
            else:
                j = result[j]
        return result

    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        size1, size2 = len(haystack), len(needle)
        if size1 < size2:
            return -1
        if size2 == 0:
            return 0
        nex = self.generate_next(needle)
        i, j = 0, 0
        while i < size1 and j < size2:
            if haystack[i] == needle[j]:
                i += 1
                j += 1
            else:
                j = nex[j]
                if j == -1:
                    i += 1
                    j = 0
        if j == size2:
            return i - j
        else:
            return -1
