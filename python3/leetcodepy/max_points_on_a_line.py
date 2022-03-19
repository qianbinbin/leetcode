"""
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.



Example 1:
https://assets.leetcode.com/uploads/2021/02/25/plane1.jpg

Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:
https://assets.leetcode.com/uploads/2021/02/25/plane2.jpg

Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4


Constraints:

1 <= points.length <= 300
points[i].length == 2
-10^4 <= xi, yi <= 10^4
All the points are unique.
"""
from collections import Counter
from typing import List


class Solution1:
    class Slope:
        def __init__(self, delta_x, delta_y):
            if delta_x == 0 and delta_y == 0:
                raise ValueError
            self.__delta_x = delta_x
            self.__delta_y = delta_y
            self.__hash = 0

        def __eq__(self, other):
            if not isinstance(other, self.__class__):
                return False
            return self.__delta_x * other.__delta_y == self.__delta_y * other.__delta_x

        def __hash__(self):
            if self.__hash != 0:
                return self.__hash
            self.__hash = hash(float('inf')) if self.__delta_x == 0 else hash(self.__delta_y / self.__delta_x)
            return self.__hash

    def maxPoints(self, points: List[List[int]]) -> int:
        size = len(points)
        if size < 3:
            return size
        result = 0
        for i in range(size - 1):
            p = points[i]
            max_count = 0
            same_point = 0
            slope_counter = Counter()
            for j in range(i + 1, size):
                q = points[j]
                if p[0] == q[0] and p[1] == q[1]:
                    same_point += 1
                    continue
                slope = self.Slope(p[0] - q[0], p[1] - q[1])
                slope_counter[slope] += 1
                max_count = max(max_count, slope_counter[slope])
            result = max(result, max_count + 1 + same_point)
        return result
