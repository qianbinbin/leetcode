#ifndef LEETCODE_TWO_SUM_H
#define LEETCODE_TWO_SUM_H

/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum_1(int *nums, int numsSize, int target);

#endif //LEETCODE_TWO_SUM_H
