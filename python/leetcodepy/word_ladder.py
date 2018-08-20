"""
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

1. Only one letter can be changed at a time.
2. Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
"""
import string
from queue import Queue
from typing import List


class Solution1:
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        word_set = set(wordList)
        if endWord not in word_set:
            return 0
        width = len(beginWord)
        s1, s2 = {beginWord}, {endWord}
        depth = 1
        while s1 and s2:
            depth += 1
            if len(s1) > len(s2):
                s1, s2 = s2, s1
            word_set -= s1
            word_set -= s2
            s = set()
            for word in s1:
                for i in range(width):
                    old = word[i]
                    left, right = word[:i], word[i + 1:]
                    for ch in string.ascii_lowercase:
                        if ch == old:
                            continue
                        guess = left + ch + right
                        if guess in s2:
                            return depth
                        elif guess in word_set and guess not in s:
                            s.add(guess)
            s1 = s
        return 0
