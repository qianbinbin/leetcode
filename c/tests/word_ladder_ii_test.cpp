#include <gtest/gtest.h>

extern "C" {
#include "word_ladder_ii.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(word_ladder_ii_test, findLadders_126_1) {
    char *wordList1[] = {"hot", "dot", "dog", "lot", "log", "cog"};
    int returnSize1 = 0;
    int *returnColumnSizes1 = NULL;
    std::vector<std::vector<std::string>> const expected1{
            {"hit", "hot", "dot", "dog", "cog"},
            {"hit", "hot", "lot", "log", "cog"}};
    char ***actual1 = findLadders_126_1("hit", "cog", wordList1,
                                        ARR_SIZE(wordList1), &returnSize1,
                                        &returnColumnSizes1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], std::vector<std::string>(actual1[i],
                                                         actual1[i] +
                                                         returnColumnSizes1[i]));
        free(actual1[i]);
    }
    free(returnColumnSizes1);
    free(actual1);

    char *wordList2[] = {"hot", "dot", "dog", "lot", "log"};
    int returnSize2 = 0;
    int *returnColumnSizes2 = NULL;
    std::vector<std::vector<std::string>> const expected2;
    char ***actual2 = findLadders_126_1("hit", "cog", wordList2,
                                        ARR_SIZE(wordList2), &returnSize2,
                                        &returnColumnSizes2);
    ASSERT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i], std::vector<std::string>(actual2[i],
                                                         actual2[i] +
                                                         returnColumnSizes2[i]));
        free(actual2[i]);
    }
    free(returnColumnSizes2);
    free(actual2);
}
