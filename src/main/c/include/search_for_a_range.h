/*
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 */

#ifndef LEETCODE_SEARCH_FOR_A_RANGE_H
#define LEETCODE_SEARCH_FOR_A_RANGE_H

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange_34_1(int *nums, int numsSize, int target, int *returnSize);

#endif //LEETCODE_SEARCH_FOR_A_RANGE_H
