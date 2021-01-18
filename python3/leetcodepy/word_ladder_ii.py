"""
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

1. Only one letter can be changed at a time
2. Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
"""
import string
from collections import defaultdict
from typing import DefaultDict, List, Set


class Solution1:
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
        result = []
        word_set = set(wordList)
        if endWord not in word_set:
            return result
        width = len(beginWord)
        s1, s2 = {beginWord}, {endWord}
        found = False
        flip = False
        graph = defaultdict(set)
        while not found and s1 and s2:
            if len(s1) > len(s2):
                s1, s2 = s2, s1
                flip = not flip
            word_set -= s1
            word_set -= s2
            s = set()
            for word in s1:
                for i in range(width):
                    left, right = word[:i], word[i + 1:]
                    old = word[i]
                    for ch in string.ascii_lowercase:
                        if ch == old:
                            continue
                        guess = left + ch + right
                        if guess in s2:
                            self.__graph_add(graph, word, guess, flip)
                            found = True
                        elif not found and guess in word_set:
                            self.__graph_add(graph, word, guess, flip)
                            if guess not in s:
                                s.add(guess)
            s1 = s
        if not found:
            return result
        self.__graph_dfs(graph, beginWord, endWord, result, [beginWord])
        return result

    def __graph_add(self, graph: DefaultDict[str, Set[str]], parent: str, child: str, flip: bool):
        if flip:
            graph[child].add(parent)
        else:
            graph[parent].add(child)

    def __graph_dfs(self, graph: DefaultDict[str, Set[str]], word: str, end_word: str,
                    result: List[List[str]], path: List[str]):
        if word == end_word:
            result.append(path[:])
            return
        for s in graph[word]:
            path.append(s)
            self.__graph_dfs(graph, s, end_word, result, path)
            path.pop()
