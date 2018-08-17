"""
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
"""
from collections import Counter


class Solution1:
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        len_s = len(s)
        len_t = len(t)
        t = Counter(t)
        count = 0
        counter = Counter()
        i, j = 0, 0
        min_start, min_len = 0, len_s + 1
        while j < len_s:
            if s[j] in t:
                if counter[s[j]] < t[s[j]]:
                    count += 1
                counter[s[j]] += 1
            j += 1
            while count == len_t:
                if j - i < min_len:
                    min_len = j - i
                    min_start = i
                if s[i] in t:
                    counter[s[i]] -= 1
                    if counter[s[i]] < t[s[i]]:
                        count -= 1
                i += 1
        if min_len > len_s:
            return ''
        return s[min_start:min_start + min_len]
