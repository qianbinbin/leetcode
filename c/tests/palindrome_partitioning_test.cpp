#include <gtest/gtest.h>

extern "C" {
#include "palindrome_partitioning.h"
}

TEST(palindrome_partitioning_test, partition_131_1) {
    int returnSize1 = 0;
    int *returnColumnSizes1 = NULL;
    std::vector<std::vector<std::string>> const expected1{{"a",  "a", "b"},
                                                          {"aa", "b"}};
    char ***actual1 = partition_131_1("aab", &returnSize1, &returnColumnSizes1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        for (int j = 0; j < returnColumnSizes1[i]; ++j) {
            EXPECT_EQ(expected1[i][j], actual1[i][j]);
            free(actual1[i][j]);
        }
        free(actual1[i]);
    }
    free(returnColumnSizes1);
    free(actual1);

    int returnSize2 = 0;
    int *returnColumnSizes2 = NULL;
    std::vector<std::vector<std::string>> const expected2{{"a"}};
    char ***actual2 = partition_131_1("a", &returnSize2, &returnColumnSizes2);
    ASSERT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        for (int j = 0; j < returnColumnSizes2[i]; ++j) {
            EXPECT_EQ(expected2[i][j], actual2[i][j]);
            free(actual2[i][j]);
        }
        free(actual2[i]);
    }
    free(returnColumnSizes2);
    free(actual2);
}
