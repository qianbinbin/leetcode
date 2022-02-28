"""
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.



Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.


Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
"""
import string
from typing import List


class Solution1:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        word_set = set(wordList)
        if endWord not in word_set:
            return 0
        word_set.remove(endWord)
        word_set.discard(beginWord)
        width = len(beginWord)
        s1, s2 = {beginWord}, {endWord}
        depth = 1
        while s1 and s2:
            depth += 1
            if len(s1) > len(s2):
                s1, s2 = s2, s1
            _next = set()
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
                        if guess in word_set:
                            word_set.remove(guess)
                            _next.add(guess)
            s1 = _next
        return 0
