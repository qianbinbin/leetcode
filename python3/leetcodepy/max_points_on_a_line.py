"""
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o
+------------->
0  1  2  3  4

Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
"""
from collections import Counter
from typing import List

from .utils import Point


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
            if self.__delta_x == 0:
                result = hash(float('inf'))
            else:
                result = hash(self.__delta_y / self.__delta_x)
            self.__hash = result
            return result

    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        size = len(points)
        if size < 3:
            return size
        result = 0
        for i in range(size - 1):
            p = points[i]
            max_local = 0
            same_point = 0
            slope_counter = Counter()
            for j in range(i + 1, size):
                q = points[j]
                if p.x == q.x and p.y == q.y:
                    same_point += 1
                    continue
                slope = self.Slope(q.x - p.x, q.y - p.y)
                slope_counter[slope] += 1
                max_local = max(max_local, slope_counter[slope])
            result = max(result, max_local + 1 + same_point)
        return result
