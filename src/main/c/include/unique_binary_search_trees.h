/*
 * Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
 *
 * Example:
 *
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 */

#ifndef LEETCODE_UNIQUE_BINARY_SEARCH_TREES_H
#define LEETCODE_UNIQUE_BINARY_SEARCH_TREES_H

int numTrees_96_1(int n);

int numTrees_96_2(int n);

#endif //LEETCODE_UNIQUE_BINARY_SEARCH_TREES_H
