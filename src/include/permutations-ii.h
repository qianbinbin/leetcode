#ifndef LEETCODE_PERMUTATIONS_II_H
#define LEETCODE_PERMUTATIONS_II_H

/**
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [
 *   [1,1,2],
 *   [1,2,1],
 *   [2,1,1]
 * ]
 *
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int **permuteUnique_47(int *nums, int numsSize, int *returnSize);

#endif //LEETCODE_PERMUTATIONS_II_H
