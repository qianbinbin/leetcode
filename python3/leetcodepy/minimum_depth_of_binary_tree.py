"""
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.



Example 1:
https://assets.leetcode.com/uploads/2020/10/12/ex_depth.jpg

Input: root = [3,9,20,null,null,15,7]
Output: 2

Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5


Constraints:

The number of nodes in the tree is in the range [0, 10^5].
-1000 <= Node.val <= 1000
"""
from typing import Optional

from .utils import TreeNode


class Solution1:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        left = self.minDepth(root.left)
        right = self.minDepth(root.right)
        if left == 0:
            return right + 1
        if right == 0:
            return left + 1
        return min(left, right) + 1


class Solution2:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        queue = [root]
        level = 1
        while queue:
            _next = []
            for node in queue:
                if node.left is None and node.right is None:
                    return level
                if node.left:
                    _next.append(node.left)
                if node.right:
                    _next.append(node.right)
            queue = _next
            level += 1
        return level
