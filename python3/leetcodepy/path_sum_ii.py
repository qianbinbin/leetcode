"""
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.



Example 1:
https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Example 2:
https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg

Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:

Input: root = [1,2], targetSum = 0
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        result = []
        self.path_sum(root, targetSum, result, [])
        return result

    def path_sum(self, root: TreeNode, target_sum: int, result: List[List[int]], path: List[int]):
        if root is None:
            return
        path.append(root.val)
        if root.left is None and root.right is None and root.val == target_sum:
            result.append(path[:])
        self.path_sum(root.left, target_sum - root.val, result, path)
        self.path_sum(root.right, target_sum - root.val, result, path)
        path.pop()
