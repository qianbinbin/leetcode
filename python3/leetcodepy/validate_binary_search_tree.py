"""
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:
https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg

Input: root = [2,1,3]
Output: true

Example 2:
https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.


Constraints:

The number of nodes in the tree is in the range [1, 10^4].
-2^31 <= Node.val <= 2^31 - 1
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.is_valid_bst(root, [None])

    def is_valid_bst(self, root: Optional[TreeNode], pre: List[Optional[TreeNode]]) -> bool:
        if root is None:
            return True
        if not self.is_valid_bst(root.left, pre):
            return False
        if pre[0] is not None and pre[0].val >= root.val:
            return False
        pre[0] = root
        return self.is_valid_bst(root.right, pre)


class Solution2:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        stack = []
        node, pre = root, None
        while node is not None or stack:
            if node is not None:
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                if pre is not None and pre.val >= node.val:
                    return False
                pre = node
                node = node.right
        return True


class Solution3:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.is_valid_bst(root, -2 ** 31 - 1, 2 ** 31)

    def is_valid_bst(self, root: Optional[TreeNode], _min: int, _max: int) -> bool:
        if root is None:
            return True
        if root.val <= _min or root.val >= _max:
            return False
        return self.is_valid_bst(root.left, _min, root.val) and self.is_valid_bst(root.right, root.val, _max)
