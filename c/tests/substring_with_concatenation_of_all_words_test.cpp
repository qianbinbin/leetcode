#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "substring_with_concatenation_of_all_words.h"
}

TEST(substring_with_concatenation_of_all_words_test, findSubstring_30_1) {
    char *s1 = "barfoothefoobarman";
    char *words1[] = {"foo", "bar"};
    int const wordsSize1 = 2;
    int returnSize1 = 0;
    std::vector<int> expected1{0, 9};
    int *actual1 = findSubstring_30_1(s1, words1, wordsSize1, &returnSize1);
    EXPECT_EQ(expected1.size(), returnSize1);
    EXPECT_EQ(expected1, std::vector<int>(actual1, actual1 + returnSize1));
    free(actual1);

    char *s2 = "wordgoodgoodgoodbestword";
    char *words2[] = {"word", "good", "best", "word"};
    int const wordsSize2 = 4;
    int returnSize2 = 0;
    std::vector<int> expected2;
    int *actual2 = findSubstring_30_1(s2, words2, wordsSize2, &returnSize2);
    EXPECT_EQ(expected2.size(), returnSize2);
    EXPECT_EQ(expected2, std::vector<int>(actual2, actual2 + returnSize2));
    free(actual2);

    char *s3 = "barfoofoobarthefoobarman";
    char *words3[] = {"bar", "foo", "the"};
    int const wordsSize3 = 3;
    int returnSize3 = 0;
    std::vector<int> expected3{6, 9, 12};
    int *actual3 = findSubstring_30_1(s3, words3, wordsSize3, &returnSize3);
    EXPECT_EQ(expected3.size(), returnSize3);
    EXPECT_EQ(expected3, std::vector<int>(actual3, actual3 + returnSize3));
    free(actual3);
}
