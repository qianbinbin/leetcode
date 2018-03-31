#ifndef LEETCODE_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II_H
#define LEETCODE_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II_H

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left, *right, *next;
};

/**
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous solution still work?
 *
 * Note:
 *
 * You may only use constant extra space.
 * For example,
 * Given the following binary tree,
 *          1
 *        /  \
 *       2    3
 *      / \    \
 *     4   5    7
 * After calling your function, the tree should look like:
 *          1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \    \
 *     4-> 5 -> 7 -> NULL
 *
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect_117(struct TreeLinkNode *root);

#endif //LEETCODE_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II_H
