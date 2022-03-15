"""
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.



Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []


Constraints:

1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
"""
from typing import List


class Solution1:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        size = len(s)
        word_set = set(wordDict)
        dp = [False] * (size + 1)
        dp[0] = True
        valid = [[False] * (size + 1) for _ in range(size)]
        for j in range(1, size + 1):
            for i in range(j - 1, -1, -1):
                if dp[i] and s[i:j] in word_set:
                    dp[j] = True
                    valid[i][j] = True
        result = []
        if not dp[size]:
            return result
        self.__word_break(s, 0, valid, result, [])
        return result

    def __word_break(self, s: str, i: int, valid: List[List[bool]], result: List[str], path: List[str]):
        if i == len(s):
            result.append(' '.join(path))
            return
        for j in range(i + 1, len(s) + 1):
            if valid[i][j]:
                path.append(s[i:j])
                self.__word_break(s, j, valid, result, path)
                path.pop()
