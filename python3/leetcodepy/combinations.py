"""
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.



Example 1:

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

Example 2:

Input: n = 1, k = 1
Output: [[1]]


Constraints:

1 <= n <= 20
1 <= k <= n
"""
from typing import List


class Solution1:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []
        self.combinations(n, k, 1, result, [])
        return result

    def combinations(self, n: int, k: int, i: int, result: List[List[int]], path: List[int]):
        if len(path) == k:
            result.append(path[:])
            return
        e = n - k + len(path) + 1
        while i <= e:
            path.append(i)
            self.combinations(n, k, i + 1, result, path)
            path.pop()
            i += 1
