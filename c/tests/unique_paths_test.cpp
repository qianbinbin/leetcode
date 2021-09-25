#include <gtest/gtest.h>

extern "C" {
#include "unique_paths.h"
}

TEST(unique_paths_test, nuniquePaths_62_1) {
    EXPECT_EQ(uniquePaths_62_1(3, 7), 28);
    EXPECT_EQ(uniquePaths_62_1(3, 2), 3);
    EXPECT_EQ(uniquePaths_62_1(7, 3), 28);
    EXPECT_EQ(uniquePaths_62_1(3, 3), 6);
}

TEST(unique_paths_test, uniquePaths_62_2) {
    EXPECT_EQ(uniquePaths_62_2(3, 7), 28);
    EXPECT_EQ(uniquePaths_62_2(3, 2), 3);
    EXPECT_EQ(uniquePaths_62_2(7, 3), 28);
    EXPECT_EQ(uniquePaths_62_2(3, 3), 6);
}
