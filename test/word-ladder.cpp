#include <gtest/gtest.h>

extern "C" {
#include <word-ladder.h>
}

TEST(leetcode_127_1, normal_1) {
    char *begin = "hit";
    char *end = "cog";
    char *list[] = {"hot", "dot", "dog", "lot", "log", "cog"};
    EXPECT_EQ(ladderLength_127_1(begin, end, list, 6), 5);
}

TEST(leetcode_127_1, normal_2) {
    char *begin = "talk";
    char *end = "tail";
    char *list[] = {"talk", "tons", "fall", "tail", "gale", "hall", "negs"};
    EXPECT_EQ(ladderLength_127_1(begin, end, list, 7), 0);
}

TEST(leetcode_127_2, normal_1) {
    char *begin = "hit";
    char *end = "cog";
    char *list[] = {"hot", "dot", "dog", "lot", "log", "cog"};
    EXPECT_EQ(ladderLength_127_2(begin, end, list, 6), 5);
}

TEST(leetcode_127_2, normal_2) {
    char *begin = "talk";
    char *end = "tail";
    char *list[] = {"talk", "tons", "fall", "tail", "gale", "hall", "negs"};
    EXPECT_EQ(ladderLength_127_2(begin, end, list, 7), 0);
}
