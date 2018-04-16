#ifndef LEETCODE_WORD_LADDER_H
#define LEETCODE_WORD_LADDER_H

/**
 * Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
 *
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 * For example,
 *
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 *
 * Note:
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 *
 * UPDATE (2017/1/20):
 * The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
 */

/**
 * Using one queue
 */
int ladderLength_127_1(char *beginWord, char *endWord, char **wordList, int wordListSize);

/**
 * Using two queues
 */
int ladderLength_127_2(char *beginWord, char *endWord, char **wordList, int wordListSize);

#endif //LEETCODE_WORD_LADDER_H
