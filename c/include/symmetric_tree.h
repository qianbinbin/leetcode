/*
 * Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
 *
 *
 *
 * Example 1:
 * https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg
 *
 * Input: root = [1,2,2,3,4,4,3]
 * Output: true
 *
 * Example 2:
 * https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg
 *
 * Input: root = [1,2,2,null,3,null,3]
 * Output: false
 *
 *
 * Constraints:
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * -100 <= Node.val <= 100
 *
 *
 * Follow up: Could you solve it both recursively and iteratively?
 */

#ifndef LEETCODE_SYMMETRIC_TREE_H
#define LEETCODE_SYMMETRIC_TREE_H

#include "common.h"

#include <stdbool.h>

bool isSymmetric_101_1(struct TreeNode *root);

bool isSymmetric_101_2(struct TreeNode *root);

#endif //LEETCODE_SYMMETRIC_TREE_H
