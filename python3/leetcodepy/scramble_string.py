"""
We can scramble a string s to get a string t using the following algorithm:

1. If the length of the string is 1, stop.
2. If the length of the string is > 1, do the following:
    Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
    Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
    Apply step 1 recursively on each of the two substrings x and y.

Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.



Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at ranom index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now and the result string is "rgeat" which is s2.
As there is one possible scenario that led s1 to be scrambled to s2, we return true.

Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false

Example 3:

Input: s1 = "a", s2 = "a"
Output: true


Constraints:

s1.length == s2.length
1 <= s1.length <= 30
s1 and s2 consist of lower-case English letters.
"""


class Solution1:
    def isScramble(self, s1: str, s2: str) -> bool:
        return self._is_scramble(s1, s2, {})

    def _is_scramble(self, s1: str, s2: str, _dict: dict) -> bool:
        k = s1 + s2
        if k in _dict:
            return _dict[k]
        _len = len(s1)
        if _len == 1:
            _dict[k] = s1 == s2
            return s1 == s2
        if sorted(s1) != sorted(s2):
            _dict[k] = False
            return False
        for l in range(1, _len):
            if (self._is_scramble(s1[:l], s2[:l], _dict) and self._is_scramble(s1[l:_len], s2[l:_len], _dict)) or \
                    (self._is_scramble(s1[:l], s2[_len - l:_len], _dict) and self._is_scramble(s1[l:_len],
                                                                                               s2[:_len - l], _dict)):
                _dict[k] = True
                return True
        _dict[k] = False
        return False


class Solution2:
    def isScramble(self, s1: str, s2: str) -> bool:
        size = len(s1)
        dp = [[[False] * size for _ in range(size)] for __ in range(size + 1)]
        for i in range(size):
            for j in range(size):
                if s1[i] == s2[j]:
                    dp[1][i][j] = True
        for length in range(2, size + 1):
            for i in range(size - length + 1):
                for j in range(size - length + 1):
                    for len_ in range(1, length):
                        if dp[len_][i][j] and dp[length - len_][i + len_][j + len_] \
                                or dp[len_][i][j + length - len_] and dp[length - len_][i + len_][j]:
                            dp[length][i][j] = True
                            break
        return dp[size][0][0]
