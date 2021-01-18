/*
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 *
 * Example:
 *
 * Input: [1,1,2]
 * Output:
 * [
 *   [1,1,2],
 *   [1,2,1],
 *   [2,1,1]
 * ]
 */

#ifndef LEETCODE_PERMUTATIONS_II_H
#define LEETCODE_PERMUTATIONS_II_H

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int **permuteUnique_47_1(int *nums, int numsSize, int *returnSize);

#endif //LEETCODE_PERMUTATIONS_II_H
