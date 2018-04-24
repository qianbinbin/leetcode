#include <gtest/gtest.h>

extern "C" {
#include <unique-paths.h>
}

TEST(leetcode_62_1, normal) {
    EXPECT_EQ(uniquePaths_62_1(7, 3), 28);
    // EXPECT_EQ(uniquePaths_62_1(51, 9), 1916797311);
}
