#include <gtest/gtest.h>

extern "C" {
#include "permutation_sequence.h"
}

TEST(permutation_sequence_test, getPermutation_60_1) {
    char *str1 = getPermutation_60_1(3, 3);
    EXPECT_STREQ(str1, "213");
    free(str1);

    char *str2 = getPermutation_60_1(4, 9);
    EXPECT_STREQ(str2, "2314");
    free(str2);
}
