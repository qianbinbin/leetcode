#include <gtest/gtest.h>

extern "C" {
#include <unique_paths.h>
}

TEST(leetcode_62_1, normal) {
    EXPECT_EQ(uniquePaths_62_1(7, 3), 28);
    // EXPECT_EQ(uniquePaths_62_1(51, 9), 1916797311);
}

TEST(leetcode_62_2, normal) {
    EXPECT_EQ(uniquePaths_62_2(7, 3), 28);
    EXPECT_EQ(uniquePaths_62_2(51, 9), 1916797311);
}

TEST(leetcode_62_3, normal) {
    EXPECT_EQ(uniquePaths_62_3(7, 3), 28);
    EXPECT_EQ(uniquePaths_62_3(51, 9), 1916797311);
    EXPECT_EQ(uniquePaths_62_3(1, 1), 1);
}
