#ifndef LEETCODE_PERMUTATION_SEQUENCE_H
#define LEETCODE_PERMUTATION_SEQUENCE_H

/**
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 *
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive.
 */

/**
 * Use next-permutation
 */
char *getPermutation_60_1(int n, int k);

/**
 * O(n)
 */
char *getPermutation_60_2(int n, int k);

#endif //LEETCODE_PERMUTATION_SEQUENCE_H