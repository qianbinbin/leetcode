#include <gtest/gtest.h>

extern "C" {
#include "count_and_say.h"
}

TEST(count_and_say_test, countAndSay_38_1) {
    char *say1 = countAndSay_38_1(1);
    EXPECT_STREQ(say1, "1");
    free(say1);

    char *say2 = countAndSay_38_1(4);
    EXPECT_STREQ(say2, "1211");
    free(say2);
}
