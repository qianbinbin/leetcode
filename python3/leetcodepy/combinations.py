"""
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
"""
from typing import List


class Solution1:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        if n < 1:
            raise ValueError
        if k < 0 or k > n:
            raise ValueError
        result = []
        self.combinations(n, k, 1, result, [])
        return result

    def combinations(self, n: int, k: int, i: int, result: List[List[int]], path: List[int]):
        if len(path) == k:
            result.append(path[:])
            return
        while i <= n:
            path.append(i)
            self.combinations(n, k, i + 1, result, path)
            path.pop()
            i += 1
