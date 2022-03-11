#include <gtest/gtest.h>

extern "C" {
#include "candy.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(candy_test, candy_135_1) {
    int ratings1[] = {1, 0, 2};
    EXPECT_EQ(5, candy_135_1(ratings1, ARR_SIZE(ratings1)));

    int ratings2[] = {1, 2, 2};
    EXPECT_EQ(4, candy_135_1(ratings2, ARR_SIZE(ratings2)));
}
