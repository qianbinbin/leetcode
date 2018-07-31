/*
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Example 1:
 *
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 *
 * Example 2:
 *
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
 */

#ifndef LEETCODE_MERGE_INTERVALS_H
#define LEETCODE_MERGE_INTERVALS_H

#include "common.h"

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval *merge_56_1(struct Interval *intervals, int intervalsSize, int *returnSize);

#endif //LEETCODE_MERGE_INTERVALS_H
