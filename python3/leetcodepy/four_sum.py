"""
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
"""


class Solution1:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = []
        ordered = sorted(nums)
        i = 0
        size = len(ordered)
        while i < size - 3:
            j = i + 1
            while j < size - 2:
                m = j + 1
                n = size - 1
                while m < n:
                    s = target - ordered[i] - ordered[j]
                    val = ordered[m] + ordered[n]
                    if val < s:
                        m += 1
                        while m < n and ordered[m] == ordered[m - 1]:
                            m += 1
                    elif val > s:
                        n -= 1
                        while m < n and ordered[n] == ordered[n + 1]:
                            n -= 1
                    else:
                        result.append([ordered[i], ordered[j], ordered[m], ordered[n]])
                        m += 1
                        while m < n and ordered[m] == ordered[m - 1]:
                            m += 1
                        n -= 1
                        while m < n and ordered[n] == ordered[n + 1]:
                            n -= 1
                j += 1
                while j < size - 2 and ordered[j] == ordered[j - 1]:
                    j += 1
            i += 1
            while i < size - 3 and ordered[i] == ordered[i - 1]:
                i += 1
        return result


class Solution2:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = set()
        sums = {}
        ordered = sorted(nums)
        size = len(ordered)
        for i in range(size - 1):
            for j in range(i + 1, size):
                s = ordered[i] + ordered[j]
                if s in sums:
                    sums[s].append((i, j))
                else:
                    sums[s] = [(i, j)]

        for s1 in sums:
            pairs1 = sums[s1]
            s2 = target - s1
            if s2 in sums:
                pairs2 = sums[s2]
                for (i, j) in pairs1:
                    for (m, n) in pairs2:
                        if i != m and i != n and j != m and j != n:
                            quadruplet = [ordered[i], ordered[j], ordered[m], ordered[n]]
                            quadruplet.sort()
                            result.add(tuple(quadruplet))
        result = [list(e) for e in result]
        return result
