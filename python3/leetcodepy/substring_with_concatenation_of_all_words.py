"""
You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.



Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []

Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]


Constraints:

1 <= s.length <= 10^4
s consists of lower-case English letters.
1 <= words.length <= 5000
1 <= words[i].length <= 30
words[i] consists of lower-case English letters.
"""
from collections import Counter
from typing import List


class Solution1:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        result = []
        width = len(words[0])
        length = width * len(words)
        if len(s) < length:
            return result

        expected, actual = Counter(words), Counter()
        i, end, count = 0, len(s) - width + 1, 0
        while i < end:
            word = s[i:i + width]
            actual[word] += 1
            if expected[word] >= actual[word]:
                count += 1
                if count == len(words):
                    i -= (count - 1) * width
                    result.append(i)
                    count = 0
                    actual.clear()
                    i += 1
                else:
                    i += width
            else:
                actual.clear()
                i -= count * width - 1
                count = 0
        return result
