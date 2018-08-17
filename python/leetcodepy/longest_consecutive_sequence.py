"""
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
"""
from typing import List


class Solution1:
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        set_ = set(nums)
        for num in nums:
            if num - 1 not in set_:
                end = num + 1
                while end in set_:
                    end += 1
                result = max(result, end - num)
        return result


class Solution2:
    class UnionFind:
        def __init__(self, n):
            if n <= 0:
                raise ValueError
            self.__parent = [i for i in range(n)]
            self.__rank = [0] * n

        def find(self, x):
            if x == self.__parent[x]:
                return x
            self.__parent[x] = self.find(self.__parent[x])
            return self.__parent[x]

        def union(self, x1, x2):
            root1, root2 = self.find(x1), self.find(x2)
            if self.__rank[root1] < self.__rank[root2]:
                self.__parent[root1] = self.__parent[root2]
            else:
                self.__parent[root2] = self.__parent[root1]
                if self.__rank[root1] == self.__rank[root2]:
                    self.__rank[root2] += 1

        def max_size(self):
            result = 0
            n = len(self.__parent)
            size = [0] * n
            for i in range(n):
                root = self.find(i)
                size[root] += 1
                result = max(result, size[root])
            return result

    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        dict_ = {}
        uf = self.UnionFind(n)
        for i, num in enumerate(nums):
            if num in dict_:
                continue
            dict_[num] = i
            if num - 1 in dict_:
                uf.union(dict_[num - 1], i)
            if num + 1 in dict_:
                uf.union(dict_[num + 1], i)
        return uf.max_size()
