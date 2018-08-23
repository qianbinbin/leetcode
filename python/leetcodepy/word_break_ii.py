"""
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]

Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
"""
from typing import List


class Solution1:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        size = len(s)
        word_set = set(wordDict)
        dp = [False] * (size + 1)
        dp[0] = True
        valid = [[False] * size for _ in range(size)]
        for i in range(1, size + 1):
            for j in range(i - 1, -1, -1):
                if dp[j] and s[j:i] in word_set:
                    dp[i] = True
                    valid[j][i - 1] = True
        result = []
        if not dp[size]:
            return result
        self.__word_break(s, 0, valid, result, [])
        return result

    def __word_break(self, s: str, i: int, valid: List[List[bool]], result: List[str], path: List[str]):
        if i == len(s):
            result.append(' '.join(path))
            return
        for j in range(i, len(s)):
            if valid[i][j]:
                path.append(s[i:j + 1])
                self.__word_break(s, j + 1, valid, result, path)
                path.pop()
