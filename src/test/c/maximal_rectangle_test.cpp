#include <gtest/gtest.h>

extern "C" {
#include "maximal_rectangle.h"
}

TEST(maximal_rectangle_test, maximalRectangle_85_1) {
    char *matrix[] = {"10100",
                      "10111",
                      "11111",
                      "10010"};
    EXPECT_EQ(maximalRectangle_85_1(matrix, 4, 5), 6);
}

TEST(maximal_rectangle_test, maximalRectangle_85_2) {
    char *matrix[] = {"10100",
                      "10111",
                      "11111",
                      "10010"};
    EXPECT_EQ(maximalRectangle_85_2(matrix, 4, 5), 6);
}
