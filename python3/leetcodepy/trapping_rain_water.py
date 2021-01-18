"""
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

http://www.leetcode.com/static/images/problemset/rainwatertrap.png

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
"""


class Solution1:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if not height:
            return 0
        size = len(height)
        dp_left = [0] * size
        maximum = height[0]
        for i in range(1, size):
            dp_left[i] = maximum
            maximum = max(maximum, height[i])
        dp_right = [0] * size
        maximum = height[size - 1]
        for i in range(size - 2, -1, -1):
            dp_right[i] = maximum
            maximum = max(maximum, height[i])
        result = 0
        for i in range(1, size - 1):
            h = min(dp_left[i], dp_right[i]) - height[i]
            if h > 0:
                result += h
        return result


class Solution2:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
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
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if not height:
            return 0
        result = 0
        i, j = 0, len(height) - 1
        left_max, right_max = 0, 0
        while i < j:
            if height[i] < height[j]:
                h = left_max - height[i]
                if h > 0:
                    result += h
                else:
                    left_max = height[i]
                i += 1
            else:
                h = right_max - height[j]
                if h > 0:
                    result += h
                else:
                    right_max = height[j]
                j -= 1
        return result
