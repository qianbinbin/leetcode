/*
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 * Input: [1,2,3]
 * Output:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 */

#ifndef LEETCODE_PERMUTATIONS_H
#define LEETCODE_PERMUTATIONS_H

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int **permute_46_1(int *nums, int numsSize, int *returnSize);

#endif //LEETCODE_PERMUTATIONS_H
