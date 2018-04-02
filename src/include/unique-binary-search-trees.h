#ifndef LEETCODE_UNIQUE_BINARY_SEARCH_TREES_H
#define LEETCODE_UNIQUE_BINARY_SEARCH_TREES_H

/**
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 */
int numTrees_96(int n);

#endif //LEETCODE_UNIQUE_BINARY_SEARCH_TREES_H
