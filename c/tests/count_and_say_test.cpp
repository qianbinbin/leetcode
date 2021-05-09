#include <gtest/gtest.h>

extern "C" {
#include "count_and_say.h"
}

TEST(count_and_say_test, countAndSay_38_1) {
    int const n1 = 1;
    char const *expected1 = "1";
    char *actual1 = countAndSay_38_1(n1);
    EXPECT_STREQ(expected1, actual1);
    free(actual1);

    int const n2 = 4;
    char const *expected2 = "1211";
    char *actual2 = countAndSay_38_1(n2);
    EXPECT_STREQ(expected2, actual2);
    free(actual2);
}
