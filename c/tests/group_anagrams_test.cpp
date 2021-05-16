#include <gtest/gtest.h>

extern "C" {
#include "group_anagrams.h"
}

TEST(group_anagrams_test, groupAnagrams_49_1) {
    char *strs1[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int const strsSize1 = 6;
    int returnSize1 = 0;
    int *returnColumnSizes1 = NULL;
    std::vector<std::vector<std::string>> expected1{{"eat", "tea", "ate"},
                                                    {"tan", "nat"},
                                                    {"bat"}};
    char ***actual1 = groupAnagrams_49_1(strs1, strsSize1, &returnSize1,
                                         &returnColumnSizes1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        ASSERT_EQ(expected1[i].size(), returnColumnSizes1[i]);
        for (int j = 0; j < returnColumnSizes1[i]; ++j) {
            EXPECT_EQ(expected1[i][j], actual1[i][j]);
            free(actual1[i][j]);
        }
        free(actual1[i]);
    }
    free(actual1);
    free(returnColumnSizes1);

    char *strs2[] = {""};
    int const strsSize2 = 1;
    int returnSize2 = 0;
    int *returnColumnSizes2 = NULL;
    std::vector<std::vector<std::string>> expected2{{""}};
    char ***actual2 = groupAnagrams_49_1(strs2, strsSize2, &returnSize2,
                                         &returnColumnSizes2);
    ASSERT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        ASSERT_EQ(expected2[i].size(), returnColumnSizes2[i]);
        for (int j = 0; j < returnColumnSizes2[i]; ++j) {
            EXPECT_EQ(expected2[i][j], actual2[i][j]);
            free(actual2[i][j]);
        }
        free(actual2[i]);
    }
    free(actual2);
    free(returnColumnSizes2);

    char *strs3[] = {"a"};
    int const strsSize3 = 1;
    int returnSize3 = 0;
    int *returnColumnSizes3 = NULL;
    std::vector<std::vector<std::string>> expected3{{"a"}};
    char ***actual3 = groupAnagrams_49_1(strs3, strsSize3, &returnSize3,
                                         &returnColumnSizes3);
    ASSERT_EQ(expected3.size(), returnSize3);
    for (int i = 0; i < returnSize3; ++i) {
        ASSERT_EQ(expected3[i].size(), returnColumnSizes3[i]);
        for (int j = 0; j < returnColumnSizes3[i]; ++j) {
            EXPECT_EQ(expected3[i][j], actual3[i][j]);
            free(actual3[i][j]);
        }
        free(actual3[i]);
    }
    free(actual3);
    free(returnColumnSizes3);
}
