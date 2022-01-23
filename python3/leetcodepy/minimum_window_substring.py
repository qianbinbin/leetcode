"""
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


Constraints:

m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.


Follow up: Could you find an algorithm that runs in O(m + n) time?
"""
from collections import Counter


class Solution1:
    def minWindow(self, s: str, t: str) -> str:
        m, n = len(s), len(t)
        expected = Counter(t)
        expected_count = 0
        i, j = 0, 0
        start, _len = -1, len(s) + 1
        while j < m:
            if expected[s[j]] > 0:
                expected_count += 1
            expected[s[j]] -= 1
            while expected_count == n:
                if j - i + 1 < _len:
                    _len = j - i + 1
                    start = i
                expected[s[i]] += 1
                if expected[s[i]] > 0:
                    expected_count -= 1
                i += 1
            j += 1
        return "" if start == -1 else s[start:start + _len]
