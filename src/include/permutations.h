#ifndef LEETCODE_PERMUTATIONS_H
#define LEETCODE_PERMUTATIONS_H

/**
 * Given a collection of distinct numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 *
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int **permute_46(int *nums, int numsSize, int *returnSize);

#endif //LEETCODE_PERMUTATIONS_H
