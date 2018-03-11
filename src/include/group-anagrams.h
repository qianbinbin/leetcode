#ifndef LEETCODE_GROUP_ANAGRAMS_H
#define LEETCODE_GROUP_ANAGRAMS_H

/**
 * Given an array of strings, group anagrams together.
 *
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Return:
 *
 * [
 *   ["ate", "eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * Note: All inputs will be in lower-case.
 *
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***groupAnagrams_49(char **strs, int strsSize, int **columnSizes, int *returnSize);

#endif //LEETCODE_GROUP_ANAGRAMS_H
