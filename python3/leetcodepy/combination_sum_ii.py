"""
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]


Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
"""
from typing import List


class Solution1:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        self.combination_sum(sorted(candidates), 0, target, 0, result, [])
        return result

    def combination_sum(self, ordered: List[int], index: int, target: int, _sum: int,
                        result: List[List[int]], path: List[int]):
        if _sum == target:
            result.append(path[:])
            return
        pre, val = -1, 0
        for i in range(index, len(ordered)):
            val = ordered[i]
            if val + _sum > target:
                break
            if val == pre:
                continue
            pre = val
            path.append(val)
            self.combination_sum(ordered, i + 1, target, _sum + val, result, path)
            path.pop()
