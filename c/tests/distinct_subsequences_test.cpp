#include <gtest/gtest.h>

extern "C" {
#include "distinct_subsequences.h"
}

TEST(distinct_subsequences_test, numDistinct_115_1) {
    EXPECT_EQ(3, numDistinct_115_1("rabbbit", "rabbit"));
    EXPECT_EQ(5, numDistinct_115_1("babgbag", "bag"));
}
