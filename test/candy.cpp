#include <gtest/gtest.h>

extern "C" {
#include <candy.h>
}

TEST(leetcode_135, normal) {
    int ratings[] = {5, 1, 4, 9, 2, 8};
    EXPECT_EQ(candy_135(ratings, 6), 11);
}
