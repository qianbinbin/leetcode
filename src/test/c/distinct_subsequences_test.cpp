#include <gtest/gtest.h>

extern "C" {
#include "distinct_subsequences.h"
}

TEST(distinct_subsequences_test, numDistinct_115_1) {
    EXPECT_EQ(numDistinct_115_1("rabbbit", "rabbit"), 3);
    EXPECT_EQ(numDistinct_115_1("babgbag", "bag"), 5);
}
