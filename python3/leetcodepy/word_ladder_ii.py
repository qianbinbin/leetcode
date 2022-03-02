"""
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].



Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"

Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.


Constraints:

1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 1000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
"""
import string
from collections import defaultdict
from typing import DefaultDict, List, Set


class Solution1:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        result = []
        word_set = set(wordList)
        if endWord not in word_set:
            return result
        word_set.remove(endWord)
        word_set.discard(beginWord)

        width = len(beginWord)
        s1, s2 = {beginWord}, {endWord}
        found = False
        reverse = False
        graph = defaultdict(set)
        while not found and s1 and s2:
            if len(s1) > len(s2):
                s1, s2 = s2, s1
                reverse = not reverse
            _next = set()
            for word in s1:
                for i in range(width):
                    left, right = word[:i], word[i + 1:]
                    old = word[i]
                    for ch in string.ascii_lowercase:
                        if ch == old:
                            continue
                        guess = left + ch + right
                        if guess in s2:
                            found = True
                            self._graph_add(graph, word, guess, reverse)
                        elif not found and guess in word_set:
                            _next.add(guess)
                            self._graph_add(graph, word, guess, reverse)
            word_set -= _next
            s1 = _next
        if not found:
            return result
        self._graph_dfs(graph, beginWord, endWord, result, [beginWord])
        return result

    def _graph_add(self, graph: DefaultDict[str, Set[str]], parent: str, child: str, flip: bool):
        if flip:
            graph[child].add(parent)
        else:
            graph[parent].add(child)

    def _graph_dfs(self, graph: DefaultDict[str, Set[str]], word: str, end_word: str,
                   result: List[List[str]], path: List[str]):
        if word == end_word:
            result.append(path[:])
            return
        for s in graph[word]:
            path.append(s)
            self._graph_dfs(graph, s, end_word, result, path)
            path.pop()
