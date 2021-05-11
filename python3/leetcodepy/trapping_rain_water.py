"""
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.



Example 1:

https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9


Constraints:

n == height.length
0 <= n <= 3 * 10^4
0 <= height[i] <= 10^5
"""
from typing import List


class Solution1:
    def trap(self, height: List[int]) -> int:
        size = len(height)
        if size < 3:
            return 0
        result = 0
        left_max = [0] * size
        for i in range(1, size):
            left_max[i] = max(left_max[i - 1], height[i - 1])
        right_max = [0] * size
        for i in range(size - 2, 0, -1):
            right_max[i] = max(right_max[i + 1], height[i + 1])
            h = min(left_max[i], right_max[i]) - height[i]
            if h > 0:
                result += h
        return result


class Solution2:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        result = 0
        size = len(height)
        stack = [0]
        for i in range(1, size):
            while stack and height[i] > height[stack[-1]]:
                j = stack.pop()
                if not stack:
                    break
                left_bound = stack[-1]
                length = i - left_bound - 1
                h = min(height[left_bound], height[i]) - height[j]
                result += h * length
            stack.append(i)
        return result


class Solution3:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        result = 0
        i, j = 0, len(height) - 1
        left_max, right_max = 0, 0
        while i < j:
            if height[i] <= height[j]:
                if left_max <= height[i]:
                    left_max = height[i]
                else:
                    result += left_max - height[i]
                i += 1
            else:
                if right_max <= height[j]:
                    right_max = height[j]
                else:
                    result += right_max - height[j]
                j -= 1
        return result
