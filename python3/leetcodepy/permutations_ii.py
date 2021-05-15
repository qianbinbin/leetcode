"""
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.



Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
"""
from typing import List


class Solution1:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        result = []
        self.permute_unique(sorted(nums), [False] * len(nums), result, [])
        return result

    def permute_unique(self, ordered: List[int], visited: List[bool], result: List[List[int]], path: List[int]):
        if len(path) == len(ordered):
            result.append(path[:])
            return
        last = -1
        for i in range(len(ordered)):
            if visited[i] or (last != -1 and ordered[i] == ordered[last]):
                continue
            last = i
            path.append(ordered[i])
            visited[i] = True
            self.permute_unique(ordered, visited, result, path)
            visited[i] = False
            path.pop()
