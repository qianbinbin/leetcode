#include <gtest/gtest.h>

extern "C" {
#include <maximal_rectangle.h>
}

TEST(leetcode_85, normal) {
    char *matrix1[] = {"10100",
                       "10111",
                       "11111",
                       "10010"};
    EXPECT_EQ(maximalRectangle_85(matrix1, 4, 5), 6);
    char *matrix2[] = {"01101",
                       "11010",
                       "01110",
                       "11110",
                       "11111",
                       "00000"};
    EXPECT_EQ(maximalRectangle_85(matrix2, 6, 5), 9);
}
