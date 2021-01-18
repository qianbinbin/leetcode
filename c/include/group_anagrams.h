/*
 * Given an array of strings, group anagrams together.
 *
 * Example:
 *
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 *   ["ate","eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 *
 * Note:
 *
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 */

#ifndef LEETCODE_GROUP_ANAGRAMS_H
#define LEETCODE_GROUP_ANAGRAMS_H

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***groupAnagrams_49_1(char **strs, int strsSize, int **columnSizes, int *returnSize);

#endif //LEETCODE_GROUP_ANAGRAMS_H
