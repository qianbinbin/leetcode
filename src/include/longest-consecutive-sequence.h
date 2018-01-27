#ifndef LEETCODE_LONGEST_CONSECUTIVE_SEQUENCE_H
#define LEETCODE_LONGEST_CONSECUTIVE_SEQUENCE_H

/**
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity.
 */

/**
 * Sort, O(nlog(n))
 */
int longestConsecutive_128_1(int *nums, int numsSize);

#endif //LEETCODE_LONGEST_CONSECUTIVE_SEQUENCE_H
